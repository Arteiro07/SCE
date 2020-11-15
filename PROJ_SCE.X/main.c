/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18875
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "LCD.h"
#include "main.h"
#include "I2C/i2c.h"
#include "config_mode.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//#include "stdio.h"

/*
                         Main application
 */

volatile uint16_t timer_flag = 0;


/*

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


 */
 
void main(void)
{
    unsigned char c;
    unsigned char l;
    unsigned char hc;
    unsigned char lc;
    unsigned char c1;
    unsigned char c2;
    unsigned char buf[17];
    
    uint8_t state = 0;
        //State= 0 normal mode.
        //state=1 , blink h
        //state=2, blink m
        //state=3, blink s
        //state=4, blink C
        //State 5,6,7 alarm time change
        //state 8, blink T
        //state9, blink T value
        //state 10 blink L
        //state 11 blink Lvalue
        //state 12 Blink Alarm

    
    // initialize the device
    SYSTEM_Initialize();
    
    // initialize timer0
    TMR0_SetInterruptHandler(TMR0_callback);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    i2c1_driver_open();
    I2C_SCL = 1;
    I2C_SDA = 1;
    WPUC3 = 1;
    WPUC4 = 1;
    
    
    unsigned char ctl=1;
    LCDinit();
    
    while (1)
    {
        // Add your application code
        if (PMON != 0 && (timer_flag%PMON) == 0){
            c = tsttc();
            l = lumin();
            //D2_LED_Toggle();
        }
        checkButtonS1();
		checkButtonS2();
        
        switch(state){
			case 0:
				//normal mode
				if(btn1State == PRESSED){
					//if s1 pressed, go to conf.mode
					state = 1;
				}
				break;
			case 1:
				
				if(btn2State == PRESSED){
					//if s2 is pressed, change hours
					conf_clock_hh();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to minutes
					state = 2;
				}
				break;
			case 2:
				if(btn2State == PRESSED){
					//if s2 is pressed, change minutes
					conf_clock_mm();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to seconds
					state = 3;
				}
				break;
			case 3:
				if(btn2State == PRESSED){
					//if s2 is pressed, change seconds
					conf_clock_ss();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to alarm changes
					state = 4;
				}
				break;
			case 4:
				if(btn2State == PRESSED){
					//if s2 is pressed, go to next state - update hours
					state = 5;
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 8 - blinking T
					state = 8;
				}
				break;
			case 5:
				if(btn2State == PRESSED){
					//if s2 is pressed, change alarm hours
					conf_alarm_hh();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to alarm minutes
					state = 6;
				}
				break;
			case 6:
				if(btn2State == PRESSED){
					//if s2 is pressed, change alarm minutes
					conf_alarm_mm();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to alarm seconds
					state = 7;
				}
				break;
			case 7:
				if(btn2State == PRESSED){
					//if s2 is pressed, change alarm seconds
					conf_alarm_ss();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to blinking T
					state = 8;
				}
				break;
			case 8:
				if(btn2State == PRESSED){
					//if s2 is pressed, go to next state - update T value
					state = 9;
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 10 - blinking L
					state = 10;
				}
				break;
			case 9:
				if(btn2State == PRESSED){
					//if s2 is pressed, change temperature
					conf_temp();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to blinking L
					state = 10;
				}
				break;
			case 10:
				if(btn2State == PRESSED){
					//if s2 is pressed, go to next state - update L value
					state = 11;
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 12 - blinking A
					state = 12;
				}
				break;
			case 11:
				if(btn2State == PRESSED){
					//if s2 is pressed, change luminosity
					conf_lumin();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to blinking A
					state = 12;
				}
				break;
			case 12:
				if(btn2State == PRESSED){
					//if s2 is pressed, toggle or untoggle alarms
					conf_alarm_flag();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 0 - normal mode
					state = 0;
				}
				break;
		}
	
        
        
        lcd(c, l, ALAF, ctl, CLKH, CLKM, (timer_flag%60), state, ALAT, ALAL, ALAH, ALAM, ALAS);
    }
}

void TMR0_callback(void){
    timer_flag++;
    if(timer_flag % 60 == 0){
        CLKM++;
        //send time to EEPROM
    }
    if(CLKM % 60 == 0 && CLKM != 0){
        CLKH++;
        CLKH %= 24;
        CLKM = 0;

        DATAEE_WriteByte(159,CLKH);
        DATAEE_WriteByte(160,CLKM);
        //DATAEE_WriteByte(161,CSUM);
    }
}

/* Register are from address 0 to 125 of EEPROM*/
void save_register(unsigned char l, unsigned char c){
    static uint16_t n = 0;
    log buf;
    buf.hour = CLKH;
    buf.min = CLKM;
    buf.sec = (timer_flag%60);
    buf.temp = c;
    buf.lum = l;
    reg[n] = buf;
    DATAEE_WriteByte(n++,buf.hour);
    DATAEE_WriteByte(n++,buf.min);
    DATAEE_WriteByte(n++,buf.sec);
    DATAEE_WriteByte(n++,buf.temp);
    DATAEE_WriteByte(n++,buf.lum);
    n = n % (5*NREG);
}

void checkButtonS1(void) {
    if (btn1State == NOT_PRESSED) {
        if (SWITCH_S1_PORT == LOW) {
            __delay_ms(200);
            btn1State = PRESSED;
        }
    } else if (SWITCH_S1_PORT == HIGH) {
        btn1State = NOT_PRESSED;
    }
}

void checkButtonS2(void) {
    if (btn2State == NOT_PRESSED) {
        if (SWITCH_S2_PORT == LOW) {
            __delay_ms(200);
            btn2State = PRESSED;
        }
        
    } else if (SWITCH_S2_PORT == HIGH) {
        btn2State = NOT_PRESSED;
    }
}


//DATAEE_ReadByte(uint16_t bAdd);

//DATAEE_WriteByte(uint16_t bAdd, uint8_t bData);

unsigned char tsttc (void){
	unsigned char value;
do{
	IdleI2C();
	StartI2C(); IdleI2C();
    
	WriteI2C(0x9a | 0x00); IdleI2C();
	WriteI2C(0x01); IdleI2C();
	RestartI2C(); IdleI2C();
	WriteI2C(0x9a | 0x01); IdleI2C();
	value = ReadI2C(); IdleI2C();
	NotAckI2C(); IdleI2C();
	StopI2C();
} while (!(value & 0x40));

	IdleI2C();
	StartI2C(); IdleI2C();
	WriteI2C(0x9a | 0x00); IdleI2C();
	WriteI2C(0x00); IdleI2C();
	RestartI2C(); IdleI2C();
	WriteI2C(0x9a | 0x01); IdleI2C();
	value = ReadI2C(); IdleI2C();
	NotAckI2C(); IdleI2C();
	StopI2C();

	return value;
}


///*

void conf_clock_hh(void){
	if (CLKH == 23){
		CLKH = 0;
	}else{
		CLKH++;
	}

	return;
}

void conf_clock_mm(void){
	if (CLKM == 59){
		CLKM = 0;
	}else{
		CLKM++;
	}

	return;
}

void conf_clock_ss(void){
	timer_flag++;
	return;
}

void conf_alarm_hh(void){
	if (ALAH == 23){
		ALAH = 0;
	}else{
		ALAH++;
	}

	return;
}

void conf_alarm_mm(void){
	if (ALAM == 59){
		ALAM = 0;
	}else{
		ALAM++;
	}

	return;
}

void conf_alarm_ss(void){
	if (ALAS == 59){
		ALAS = 0;
	}else{
		ALAS++;
	}

	return;
}

void conf_temp(void){

	if(ALAT == T_MAX){
		ALAT = T_MIN;
	}else{
		ALAT++;
    }
	return;
}


void conf_lumin(void){

	if(ALAL == L_MAX){
		ALAL = L_MIN;
	}else{
		ALAL++;
	}

	return;
}

void conf_alarm_flag(void){

	if(ALAF == 0){
		ALAF = 1;
	}else{
		ALAF = 0;
	}

	return;
}

//*/
/**
 End of File
*/
