/* 
 * File:   main.h
 * Author: joaom
 *
 * Created on November 15, 2020, 4:21 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif


typedef struct _log{
    uint8_t hour;      
    uint8_t min;
    uint8_t sec;      
    uint8_t temp;
    uint8_t lum;
}log;



#define PRESSED             1
#define NOT_PRESSED         0

#define T_MIN         		0
#define T_MAX         		50
#define L_MIN         		0
#define L_MAX         		7


#define PASS 0xaa      //magic word                                 150
#define NREG 25        //number of data registers                         
uint8_t PMON = 3;      //sec monitoring period                      151
uint8_t TALA = 5;      //sec duration of alarm signal (PWM)         152
uint8_t ALAH = 12;     //hours of alarm clock                       153
uint8_t ALAM = 0;      //minutes of alarm clock                     154
uint8_t ALAS = 0;      //seconds of alarm clock                     155
uint8_t ALAT = 28;     //threshold for temperature alarm            156
uint8_t ALAL = 4;      //threshold for luminosity level alarm       157
uint8_t ALAF = 0;      //alarm flag ? starts disabled               158
uint8_t CLKH = 0;      //initial value for clock hours              159
uint8_t CLKM = 0;      //initial value for clock minutes            160
uint8_t CSUM = 0;      //checksum for EEPROM                        161

log reg[NREG];


uint8_t btn1State = NOT_PRESSED;
uint8_t btn2State = NOT_PRESSED;    


void TMR0_callback(void);
void save_register(unsigned char l, unsigned char c);
void checkButtonS1(void);
void checkButtonS2(void);
unsigned char tsttc (void);

///*
void conf_clock_hh(void);
void conf_clock_mm(void);
void conf_clock_ss(void);
void conf_alarm_hh(void);
void conf_alarm_mm(void);
void conf_alarm_ss(void);
void conf_temp(void);
void conf_lumin(void);
void conf_alarm_flag(void);
//*/




#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

