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

// get/set SWITCH_S2 aliases
#define SWITCH_S1_TRIS                 TRISCbits.TRISC5
#define SWITCH_S1_LAT                  LATCbits.LATC5
#define SWITCH_S1_PORT                 PORTCbits.RC5
#define SWITCH_S1_WPU                  WPUCbits.WPUC5
#define SWITCH_S1_OD                   ODCONCbits.ODCC5
#define SWITCH_S1_ANS                  ANSELCbits.ANSC5
#define SWITCH_S1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SWITCH_S1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SWITCH_S1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SWITCH_S1_GetValue()           PORTCbits.RC5
#define SWITCH_S1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SWITCH_S1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SWITCH_S1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SWITCH_S1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SWITCH_S1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SWITCH_S1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SWITCH_S1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SWITCH_S1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)