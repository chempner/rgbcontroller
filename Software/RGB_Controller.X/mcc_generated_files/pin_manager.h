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

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSELA5 = 0; } while(0)

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

// get/set POT2 aliases
#define POT2_TRIS                 TRISCbits.TRISC3
#define POT2_LAT                  LATCbits.LATC3
#define POT2_PORT                 PORTCbits.RC3
#define POT2_WPU                  WPUCbits.WPUC3
#define POT2_OD                   ODCONCbits.ODCC3
#define POT2_ANS                  ANSELCbits.ANSELC3
#define POT2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define POT2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define POT2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define POT2_GetValue()           PORTCbits.RC3
#define POT2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define POT2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define POT2_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define POT2_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define POT2_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define POT2_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define POT2_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define POT2_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set POT1 aliases
#define POT1_TRIS                 TRISCbits.TRISC4
#define POT1_LAT                  LATCbits.LATC4
#define POT1_PORT                 PORTCbits.RC4
#define POT1_WPU                  WPUCbits.WPUC4
#define POT1_OD                   ODCONCbits.ODCC4
#define POT1_ANS                  ANSELCbits.ANSELC4
#define POT1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define POT1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define POT1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define POT1_GetValue()           PORTCbits.RC4
#define POT1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define POT1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define POT1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define POT1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define POT1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define POT1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define POT1_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define POT1_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set POT3 aliases
#define POT3_TRIS                 TRISCbits.TRISC6
#define POT3_LAT                  LATCbits.LATC6
#define POT3_PORT                 PORTCbits.RC6
#define POT3_WPU                  WPUCbits.WPUC6
#define POT3_OD                   ODCONCbits.ODCC6
#define POT3_ANS                  ANSELCbits.ANSELC6
#define POT3_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define POT3_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define POT3_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define POT3_GetValue()           PORTCbits.RC6
#define POT3_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define POT3_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define POT3_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define POT3_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define POT3_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define POT3_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define POT3_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define POT3_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set POT4 aliases
#define POT4_TRIS                 TRISCbits.TRISC7
#define POT4_LAT                  LATCbits.LATC7
#define POT4_PORT                 PORTCbits.RC7
#define POT4_WPU                  WPUCbits.WPUC7
#define POT4_OD                   ODCONCbits.ODCC7
#define POT4_ANS                  ANSELCbits.ANSELC7
#define POT4_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define POT4_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define POT4_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define POT4_GetValue()           PORTCbits.RC7
#define POT4_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define POT4_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define POT4_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define POT4_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define POT4_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define POT4_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define POT4_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define POT4_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

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