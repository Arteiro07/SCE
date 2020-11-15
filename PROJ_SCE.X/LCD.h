/* 
 * File:   LCD.h
 * Author: joaom
 *
 * Created on November 15, 2020, 4:21 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void LCDsend(unsigned char c);
unsigned char LCDrecv(unsigned char mode);
void LCDsend2x4(unsigned char c, unsigned char mode);
void LCDinit(void);
void LCDcmd(unsigned char c);
void LCDchar(unsigned char c);
void LCDstr(unsigned char *p);
int LCDbusy();
bool lcd(unsigned char temperature, unsigned char luminosity, unsigned char alarm, unsigned char ctl, unsigned char h, unsigned char m, unsigned char s, unsigned char state, unsigned char temperature_alarm, unsigned char luminosity_alarm, unsigned char alah, unsigned char alam,unsigned char alas );
unsigned char lumin(void);



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

