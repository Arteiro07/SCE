/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18875
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set CH_0 aliases
#define CH_0_TRIS                 TRISAbits.TRISA0
#define CH_0_LAT                  LATAbits.LATA0
#define CH_0_PORT                 PORTAbits.RA0
#define CH_0_WPU                  WPUAbits.WPUA0
#define CH_0_OD                   ODCONAbits.ODCA0
#define CH_0_ANS                  ANSELAbits.ANSA0
#define CH_0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define CH_0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define CH_0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define CH_0_GetValue()           PORTAbits.RA0
#define CH_0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define CH_0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define CH_0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define CH_0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define CH_0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define CH_0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define CH_0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define CH_0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set D2_LED aliases
#define D2_LED_TRIS                 TRISAbits.TRISA4
#define D2_LED_LAT                  LATAbits.LATA4
#define D2_LED_PORT                 PORTAbits.RA4
#define D2_LED_WPU                  WPUAbits.WPUA4
#define D2_LED_OD                   ODCONAbits.ODCA4
#define D2_LED_ANS                  ANSELAbits.ANSA4
#define D2_LED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define D2_LED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define D2_LED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define D2_LED_GetValue()           PORTAbits.RA4
#define D2_LED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define D2_LED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define D2_LED_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define D2_LED_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define D2_LED_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define D2_LED_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define D2_LED_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define D2_LED_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SWITCH_S1 aliases
#define SWITCH_S1_TRIS                 TRISBbits.TRISB4
#define SWITCH_S1_LAT                  LATBbits.LATB4
#define SWITCH_S1_PORT                 PORTBbits.RB4
#define SWITCH_S1_WPU                  WPUBbits.WPUB4
#define SWITCH_S1_OD                   ODCONBbits.ODCB4
#define SWITCH_S1_ANS                  ANSELBbits.ANSB4
#define SWITCH_S1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SWITCH_S1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SWITCH_S1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SWITCH_S1_GetValue()           PORTBbits.RB4
#define SWITCH_S1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SWITCH_S1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SWITCH_S1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SWITCH_S1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SWITCH_S1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SWITCH_S1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SWITCH_S1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SWITCH_S1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC3
#define SCL1_LAT                  LATCbits.LATC3
#define SCL1_PORT                 PORTCbits.RC3
#define SCL1_WPU                  WPUCbits.WPUC3
#define SCL1_OD                   ODCONCbits.ODCC3
#define SCL1_ANS                  ANSELCbits.ANSC3
#define SCL1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL1_GetValue()           PORTCbits.RC3
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC4
#define SDA1_LAT                  LATCbits.LATC4
#define SDA1_PORT                 PORTCbits.RC4
#define SDA1_WPU                  WPUCbits.WPUC4
#define SDA1_OD                   ODCONCbits.ODCC4
#define SDA1_ANS                  ANSELCbits.ANSC4
#define SDA1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA1_GetValue()           PORTCbits.RC4
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SWITCH_S2 aliases
#define SWITCH_S2_TRIS                 TRISCbits.TRISC5
#define SWITCH_S2_LAT                  LATCbits.LATC5
#define SWITCH_S2_PORT                 PORTCbits.RC5
#define SWITCH_S2_WPU                  WPUCbits.WPUC5
#define SWITCH_S2_OD                   ODCONCbits.ODCC5
#define SWITCH_S2_ANS                  ANSELCbits.ANSC5
#define SWITCH_S2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SWITCH_S2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SWITCH_S2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SWITCH_S2_GetValue()           PORTCbits.RC5
#define SWITCH_S2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SWITCH_S2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SWITCH_S2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SWITCH_S2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SWITCH_S2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SWITCH_S2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SWITCH_S2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SWITCH_S2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/