#include "mcc_generated_files/mcc.h"
#include "I2C/i2c.h"
#include <math.h>
//#include "stdio.h"

/*
                         Main application
 */



#define LCD_ADDR 0x4e   // 0x27 << 1
#define LCD_BL 0x08
#define LCD_EN 0x04
#define LCD_RW 0x02
#define LCD_RS 0x01

void LCDsend(unsigned char c)
{
  IdleI2C();
  StartI2C(); IdleI2C();
  WriteI2C(LCD_ADDR | 0x00); IdleI2C();
  WriteI2C(c); IdleI2C();
  StopI2C();    
}
unsigned char LCDrecv(unsigned char mode)
{
  unsigned char hc;
  unsigned char lc;
  
  IdleI2C();
  StartI2C(); IdleI2C();
  WriteI2C(LCD_ADDR | 0x00); IdleI2C();
  WriteI2C(0xf0 | LCD_BL | LCD_RW | mode); IdleI2C();
  WriteI2C(0xf0 | LCD_BL | LCD_EN | LCD_RW | mode); IdleI2C();
  __delay_us(1);
  RestartI2C(); IdleI2C();
  WriteI2C(LCD_ADDR | 0x01); IdleI2C();
  hc = ReadI2C(); IdleI2C();
  NotAckI2C();
  RestartI2C(); IdleI2C();
  WriteI2C(LCD_ADDR | 0x00); IdleI2C();
  WriteI2C(0xf0 | LCD_BL | LCD_RW | mode); IdleI2C();
  WriteI2C(0xf0 | LCD_BL | LCD_EN | LCD_RW | mode); IdleI2C();
  __delay_us(1);
  RestartI2C(); IdleI2C();
  WriteI2C(LCD_ADDR | 0x01); IdleI2C();
  lc = ReadI2C(); IdleI2C();
  NotAckI2C();
  RestartI2C(); IdleI2C();
  WriteI2C(LCD_ADDR | 0x00); IdleI2C();
  WriteI2C(0xf0 | LCD_BL | LCD_RW | mode); IdleI2C();
  StopI2C();
  return ((hc&0xf0) | ((lc>>4)&0x0f));
}

void LCDsend2x4(unsigned char c, unsigned char mode)
{
  unsigned char hc;
  unsigned char lc;
  
  hc = c & 0xf0;
  lc = (c << 4) & 0xf0;
    
  IdleI2C();
  StartI2C(); IdleI2C();
  WriteI2C(LCD_ADDR | 0x00); IdleI2C();
  WriteI2C(hc | LCD_BL | mode); IdleI2C();
  WriteI2C(hc | LCD_BL | LCD_EN | mode); IdleI2C();
  __delay_us(1);
  WriteI2C(hc | LCD_BL | mode); IdleI2C();
  WriteI2C(lc | LCD_BL | mode); IdleI2C();
  WriteI2C(lc | LCD_BL | LCD_EN | mode); IdleI2C();
  __delay_us(1);
  WriteI2C(lc | LCD_BL | mode); IdleI2C();
  StopI2C();    
  __delay_us(50);
}

void LCDinit(void)
{
    __delay_ms(50);
    LCDsend(0x30);
    LCDsend(0x34); __delay_us(500); LCDsend(0x30);
    __delay_ms(5);
    LCDsend(0x30);
    LCDsend(0x34); __delay_us(500); LCDsend(0x30);
    __delay_us(100);
    LCDsend(0x30);
    LCDsend(0x34); __delay_us(500); LCDsend(0x30);
    __delay_us(100);
    LCDsend(0x20);
    LCDsend(0x24); __delay_us(500); LCDsend(0x20);
    __delay_ms(5);

    LCDsend2x4(0x28, 0);
    LCDsend2x4(0x06, 0);
    LCDsend2x4(0x0f, 0);
    LCDsend2x4(0x01, 0);
    __delay_ms(2);
}

void LCDcmd(unsigned char c)
{
  LCDsend2x4(c, 0);
}

void LCDchar(unsigned char c)
{
  LCDsend2x4(c, LCD_RS);
}

void LCDstr(unsigned char *p)
{
  unsigned char c;
  
  while((c = *p++)) LCDchar(c);
}

int LCDbusy()
{
    if(LCDrecv(0) & 0x80) return 1;
    return 0;
}


bool lcd(unsigned char temperature, unsigned char luminosity, unsigned char alarm, unsigned char ctl, unsigned char h, unsigned char m, unsigned char s, unsigned char state, unsigned char temperature_alarm, unsigned char luminosity_alarm, unsigned char alah, unsigned char alam,unsigned char alas )
{
    unsigned char buf[17];    
    
    
    if (alarm)    
    {
        LCDcmd(0x8F);
        sprintf(buf, "A");
        LCDstr(buf);        
    }
    else
    {
        LCDcmd(0x8F);
        sprintf(buf, "a");
        LCDstr(buf);
    }
    if(state==0)
    {    
        LCDcmd(0x80);
        sprintf(buf, "%02d:%02d:%02d", h,m,s);
        LCDstr(buf);
    
        LCDcmd(0xc0);
        sprintf(buf, "%02d C", temperature);
        LCDstr(buf);

        LCDcmd(0xce);
        sprintf(buf, "L%01d", luminosity);
        LCDstr(buf);
        
        if (ctl==1)   
        {
            LCDcmd(0x8A);
            sprintf(buf, "C");
            LCDstr(buf);
            LCDcmd(0x9A);
        }   
        else if (ctl==2)
        {
            LCDcmd(0x8A);
            sprintf(buf, "T");
            LCDstr(buf);
            LCDcmd(0x9A);
        }
        else if (ctl== 3)
        {
            LCDcmd(0x8A);
            sprintf(buf, "L");
            LCDstr(buf);
            LCDcmd(0x9A);
        }
        else
        {
            LCDcmd(0x8A);
            sprintf(buf, " ");
            LCDstr(buf);
            LCDcmd(0x9A);
        }

    }
    else
    {

        
        if (state ==1) // changing hours
        {
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", h,m,s);
            LCDstr(buf);

            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x81);
            
        }
        if (state ==2)
        {
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", h,m,s);
            LCDstr(buf);

            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x84);
        }
        if (state ==3)
        {
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", h,m,s);
            LCDstr(buf);

            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x87);
        }
        //////////////////////////////////////////        
        // Change to C clock alarm
        if (state ==4)
        {
            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", alah, alam, alas);  //change to alarm time
            LCDstr(buf);
            LCDcmd(0x8a);
        }
        // Change the alarm time h1
        if (state ==5)
        {
            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", alah, alam, alas);  //change to alarm time
            LCDstr(buf);
            LCDcmd(0x81);
            
        }
        // Change the alarm time m1
        if (state ==6)
        {
            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", alah, alam, alas);  //change to alarm time
            LCDstr(buf);
            LCDcmd(0x84);
            
        }
        // Change the alarm time s1
        if (state ==7)
        {
            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x81);            
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", alah, alam, alas);  //change to alarm time
            LCDstr(buf);
            LCDcmd(0x87);
            
        }
        /////////////////////////////////////////////
        // Change to T temperature alarm
        if (state ==8)
        {
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", h,m,s);
            LCDstr(buf);

            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x81);
            
            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature_alarm);
            LCDstr(buf);
            LCDcmd(0x8b);
        }
                
        
        // Change the alarm temp1
        if (state ==9)
        {
                        LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", h,m,s);
            LCDstr(buf);

            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity);
            LCDstr(buf);
            LCDcmd(0x81);
            
            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature_alarm);
            LCDstr(buf);
            LCDcmd(0xc1);
        }
        
        ///////////////////////////////////////
        // Change to L luminosity alarm
        if (state ==10)
        {
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", h,m,s);
            LCDstr(buf);

            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);
            
            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity_alarm);
            LCDstr(buf);            
            LCDcmd(0x8c);
        }

        // Change the alarm lum1
        if (state ==11)
        {
            LCDcmd(0x80);
            sprintf(buf, "%02d:%02d:%02d", h,m,s);
            LCDstr(buf);

            LCDcmd(0x8A);
            sprintf(buf, "CTL");
            LCDstr(buf);

            LCDcmd(0xc0);
            sprintf(buf, "%02d C", temperature);
            LCDstr(buf);
            
            LCDcmd(0xce);
            sprintf(buf, "L%01d", luminosity_alarm);
            LCDstr(buf);
            LCDcmd(0xcf);
        }
        // Change the alarm enable/disable
        if (state ==12)
        {
            LCDcmd(0x8A);
            sprintf(buf, "   ");
            LCDstr(buf);
    
            
            LCDcmd(0x8f);
            
            
        }
    }    
    return(true);
}


unsigned char lumin(void)
{
    unsigned short luminosity;
    ADCC_Initialize();
    ADCC_StartConversion(CH_0);
    luminosity = 0x0000;
    luminosity = ADCC_GetConversionResult();
    luminosity = luminosity << 6;
    luminosity = luminosity >>13;
    return(luminosity);
}
