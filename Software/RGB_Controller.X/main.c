#include "mcc_generated_files/mcc.h"
#include "DivFunctions.h"
#include "Loopdelay.h"

#define LEDCOUNT 3

#define EE_STATECHECKBYTEADD    22
#define EE_MODE1CHECKBYTEADD    23
#define EE_MODE2CHECKBYTEADD    24
#define EE_MODE3CHECKBYTEADD    26
#define EE_MODE4CHECKBYTEADD    28
#define EE_MODE1_REDADD         31
#define EE_MODE1_GREENADD       33
#define EE_MODE1_BLUEADD        34
#define EE_MODE1_WHITEADD       36
#define EE_MODE2_REDADD         37
#define EE_MODE2_GREENADD       38
#define EE_MODE2_BLUEADD        39
#define EE_MODE2_WHITEADD       41
#define EE_MODE3_REDADD         43
#define EE_MODE3_GREENADD       45
#define EE_MODE3_BLUEADD        46
#define EE_MODE3_WHITEADD       48
#define EE_MODE4_REDADD         50
#define EE_MODE4_GREENADD       51
#define EE_MODE4_BLUEADD        53
#define EE_MODE4_WHITEADD       55
#define EE_STATEBYTEADD         56

#define EE_CHECKBYTEDATA        69

#define LOOPTIME        10

#define TIMEOUT1S       100
#define TIMEOUT5S       500
#define TIMEOUT100MS    10

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    SPI1_Open(SPI1_DEFAULT);
    INTERRUPT_GlobalInterruptEnable();

    TMR2_SetInterruptHandler(LOOPDELAY_TimerISR);
    
    uint8_t red, green, blue, white = 0;
    uint8_t taster1Flag = 0;
    uint8_t taster2Flag = 0;
    uint8_t taster3Flag = 0;
    uint8_t taster4Flag = 0;    
    
    /*Statemachine Init*/
    typedef enum
    {
        MANUAL, T1, T2, T3, T4
    }state_t;
    
    state_t state = MANUAL;
    
    
    /*Check if State is stored in EEPROM*/
    if(EEPROM_READ(EE_STATECHECKBYTEADD) == EE_CHECKBYTEDATA)
    {
        state = EEPROM_READ(EE_STATEBYTEADD);
       
        if(state == 1)
        {
            if(EEPROM_READ(EE_MODE1CHECKBYTEADD) == EE_CHECKBYTEDATA)
            {
                red = EEPROM_READ(EE_MODE1_REDADD);
                green = EEPROM_READ(EE_MODE1_GREENADD);
                blue = EEPROM_READ(EE_MODE1_BLUEADD);
                white = EEPROM_READ(EE_MODE1_WHITEADD);
                LED_WriteFull(red, green, blue, white, LEDCOUNT);
            }
            
            else
            {
                state = MANUAL;
            }
        }
        
        if(state == 2)
        {
            if(EEPROM_READ(EE_MODE2CHECKBYTEADD) == EE_CHECKBYTEDATA)
            {
                red = EEPROM_READ(EE_MODE2_REDADD);
                green = EEPROM_READ(EE_MODE2_GREENADD);
                blue = EEPROM_READ(EE_MODE2_BLUEADD);
                white = EEPROM_READ(EE_MODE2_WHITEADD);
                LED_WriteFull(red, green, blue, white, LEDCOUNT);
            }
            
            else
            {
                state = MANUAL;
            }
        }
        
        if(state == 3)
        {
            if(EEPROM_READ(EE_MODE3CHECKBYTEADD) == EE_CHECKBYTEDATA)
            {
                red = EEPROM_READ(EE_MODE3_REDADD);
                green = EEPROM_READ(EE_MODE3_GREENADD);
                blue = EEPROM_READ(EE_MODE3_BLUEADD);
                white = EEPROM_READ(EE_MODE3_WHITEADD);
                LED_WriteFull(red, green, blue, white, LEDCOUNT);
            }
            
            else
            {
                state = MANUAL;
            }
        }
        
        if(state == 4)
        {
            if(EEPROM_READ(EE_MODE4CHECKBYTEADD) == EE_CHECKBYTEDATA)
            {
                red = EEPROM_READ(EE_MODE4_REDADD);
                green = EEPROM_READ(EE_MODE4_GREENADD);
                blue = EEPROM_READ(EE_MODE4_BLUEADD);
                white = EEPROM_READ(EE_MODE4_WHITEADD);
                LED_WriteFull(red, green, blue, white, LEDCOUNT);
            }
            
            else
            {
                state = MANUAL;
            }
        }
    }    
//=================State and Mode Check ending==============================//
    
    
    
    LOOPDELAY_Init(LOOPTIME);
    
    while (1)
    {
        LOOPDELAY_Wait();
        
        EEPROM_WRITE(EE_STATEBYTEADD, state);
        EEPROM_WRITE(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);
        
        switch(state)
        {
            case MANUAL:
                
                break;
                
            case T1:
                
                if(T1_LAT && !taster1Flag)
                {
                    state = MANUAL;
                }
                taster1Flag = T1_LAT;
                
                break;
                
            case T2:
                
                if(T2_LAT && !taster2Flag)
                {
                    state = MANUAL;
                }
                taster2Flag = T2_LAT;
                
                break;
                
            case T3:
                
                if(T3_LAT && !taster3Flag)
                {
                    state = MANUAL;
                }
                taster3Flag = T3_LAT;
                
                break;
                
            case T4:
                
                if(T4_LAT && !taster4Flag)
                {
                    state = MANUAL;
                }
                taster4Flag = T4_LAT;
                
                break;
        }
        
        ADCC_DischargeSampleCapacitor();
        red = map(ADCC_GetSingleConversion(POT1),0,4095,0,255);
        ADCC_DischargeSampleCapacitor();
        green = map(ADCC_GetSingleConversion(POT2),0,4095,0,255);
        ADCC_DischargeSampleCapacitor();
        blue = map(ADCC_GetSingleConversion(POT3),0,4095,0,255);
        ADCC_DischargeSampleCapacitor();
        white = map(ADCC_GetSingleConversion(POT4),0,4095,0,255);        
    }
}