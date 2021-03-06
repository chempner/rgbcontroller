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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F16Q40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POT1 aliases
#define POT1_TRIS                 TRISAbits.TRISA2
#define POT1_LAT                  LATAbits.LATA2
#define POT1_PORT                 PORTAbits.RA2
#define POT1_WPU                  WPUAbits.WPUA2
#define POT1_OD                   ODCONAbits.ODCA2
#define POT1_ANS                  ANSELAbits.ANSELA2
#define POT1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define POT1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define POT1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define POT1_GetValue()           PORTAbits.RA2
#define POT1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define POT1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define POT1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define POT1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define POT1_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define POT1_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define POT1_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define POT1_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set T2 aliases
#define T2_TRIS                 TRISAbits.TRISA4
#define T2_LAT                  LATAbits.LATA4
#define T2_PORT                 PORTAbits.RA4
#define T2_WPU                  WPUAbits.WPUA4
#define T2_OD                   ODCONAbits.ODCA4
#define T2_ANS                  ANSELAbits.ANSELA4
#define T2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define T2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define T2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define T2_GetValue()           PORTAbits.RA4
#define T2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define T2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define T2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define T2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define T2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define T2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define T2_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define T2_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISAbits.TRISA5
#define LED3_LAT                  LATAbits.LATA5
#define LED3_PORT                 PORTAbits.RA5
#define LED3_WPU                  WPUAbits.WPUA5
#define LED3_OD                   ODCONAbits.ODCA5
#define LED3_ANS                  ANSELAbits.ANSELA5
#define LED3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED3_GetValue()           PORTAbits.RA5
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set T4 aliases
#define T4_TRIS                 TRISBbits.TRISB7
#define T4_LAT                  LATBbits.LATB7
#define T4_PORT                 PORTBbits.RB7
#define T4_WPU                  WPUBbits.WPUB7
#define T4_OD                   ODCONBbits.ODCB7
#define T4_ANS                  ANSELBbits.ANSELB7
#define T4_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define T4_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define T4_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define T4_GetValue()           PORTBbits.RB7
#define T4_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define T4_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define T4_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define T4_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define T4_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define T4_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define T4_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define T4_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set POT2 aliases
#define POT2_TRIS                 TRISCbits.TRISC0
#define POT2_LAT                  LATCbits.LATC0
#define POT2_PORT                 PORTCbits.RC0
#define POT2_WPU                  WPUCbits.WPUC0
#define POT2_OD                   ODCONCbits.ODCC0
#define POT2_ANS                  ANSELCbits.ANSELC0
#define POT2_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define POT2_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define POT2_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define POT2_GetValue()           PORTCbits.RC0
#define POT2_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define POT2_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define POT2_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define POT2_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define POT2_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define POT2_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define POT2_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define POT2_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set POT3 aliases
#define POT3_TRIS                 TRISCbits.TRISC1
#define POT3_LAT                  LATCbits.LATC1
#define POT3_PORT                 PORTCbits.RC1
#define POT3_WPU                  WPUCbits.WPUC1
#define POT3_OD                   ODCONCbits.ODCC1
#define POT3_ANS                  ANSELCbits.ANSELC1
#define POT3_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define POT3_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define POT3_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define POT3_GetValue()           PORTCbits.RC1
#define POT3_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define POT3_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define POT3_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define POT3_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define POT3_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define POT3_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define POT3_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define POT3_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set POT4 aliases
#define POT4_TRIS                 TRISCbits.TRISC2
#define POT4_LAT                  LATCbits.LATC2
#define POT4_PORT                 PORTCbits.RC2
#define POT4_WPU                  WPUCbits.WPUC2
#define POT4_OD                   ODCONCbits.ODCC2
#define POT4_ANS                  ANSELCbits.ANSELC2
#define POT4_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define POT4_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define POT4_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define POT4_GetValue()           PORTCbits.RC2
#define POT4_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define POT4_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define POT4_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define POT4_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define POT4_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define POT4_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define POT4_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define POT4_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISCbits.TRISC3
#define LED4_LAT                  LATCbits.LATC3
#define LED4_PORT                 PORTCbits.RC3
#define LED4_WPU                  WPUCbits.WPUC3
#define LED4_OD                   ODCONCbits.ODCC3
#define LED4_ANS                  ANSELCbits.ANSELC3
#define LED4_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED4_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED4_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED4_GetValue()           PORTCbits.RC3
#define LED4_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED4_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set T3 aliases
#define T3_TRIS                 TRISCbits.TRISC4
#define T3_LAT                  LATCbits.LATC4
#define T3_PORT                 PORTCbits.RC4
#define T3_WPU                  WPUCbits.WPUC4
#define T3_OD                   ODCONCbits.ODCC4
#define T3_ANS                  ANSELCbits.ANSELC4
#define T3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define T3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define T3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define T3_GetValue()           PORTCbits.RC4
#define T3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define T3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define T3_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define T3_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define T3_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define T3_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define T3_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define T3_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISCbits.TRISC5
#define LED2_LAT                  LATCbits.LATC5
#define LED2_PORT                 PORTCbits.RC5
#define LED2_WPU                  WPUCbits.WPUC5
#define LED2_OD                   ODCONCbits.ODCC5
#define LED2_ANS                  ANSELCbits.ANSELC5
#define LED2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED2_GetValue()           PORTCbits.RC5
#define LED2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set T1 aliases
#define T1_TRIS                 TRISCbits.TRISC6
#define T1_LAT                  LATCbits.LATC6
#define T1_PORT                 PORTCbits.RC6
#define T1_WPU                  WPUCbits.WPUC6
#define T1_OD                   ODCONCbits.ODCC6
#define T1_ANS                  ANSELCbits.ANSELC6
#define T1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define T1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define T1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define T1_GetValue()           PORTCbits.RC6
#define T1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define T1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define T1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define T1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define T1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define T1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define T1_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define T1_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC7
#define LED1_LAT                  LATCbits.LATC7
#define LED1_PORT                 PORTCbits.RC7
#define LED1_WPU                  WPUCbits.WPUC7
#define LED1_OD                   ODCONCbits.ODCC7
#define LED1_ANS                  ANSELCbits.ANSELC7
#define LED1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED1_GetValue()           PORTCbits.RC7
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

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