#include "mcc_generated_files/mcc.h"
#include "DivFunctions.h"
//#include "DivFunctions.h"

#define LEDCOUNT    400
/*
                         Main application
 */


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize(); 
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    c_WS2812B_Write(150,105,150,150);
    
    while (1)
    {
        __delay_ms(10);
        
//        ADCC_DischargeSampleCapacitor();
//        red = ADCC_GetSingleConversion(POT1);
//        ADCC_DischargeSampleCapacitor();
//        green = ADCC_GetSingleConversion(POT2);
//        ADCC_DischargeSampleCapacitor();
//        blue = ADCC_GetSingleConversion(POT3);
//        ADCC_DischargeSampleCapacitor();
//        white = ADCC_GetSingleConversion(POT4);
        
//        red = 120;
//        green = 120;
//        blue = 120;
//        white = 120;
//        
        
    }
}