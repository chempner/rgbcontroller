#include "mcc_generated_files/mcc.h"
#include "DivFunctions.h"
#include "Loopdelay.h"

#define LEDCOUNT 3

#define EE_STATECHECKBYTEADD    2
#define EE_MODE1CHECKBYTEADD    3
#define EE_MODE2CHECKBYTEADD    4
#define EE_MODE3CHECKBYTEADD    6
#define EE_MODE4CHECKBYTEADD    8
#define EE_MODE1_REDADD         11
#define EE_MODE1_GREENADD       12
#define EE_MODE1_BLUEADD        15
#define EE_MODE1_WHITEADD       17
#define EE_MODE2_REDADD         18
#define EE_MODE2_GREENADD       19
#define EE_MODE2_BLUEADD        20
#define EE_MODE2_WHITEADD       21
#define EE_MODE3_REDADD         22
#define EE_MODE3_GREENADD       24
#define EE_MODE3_BLUEADD        25
#define EE_MODE3_WHITEADD       27
#define EE_MODE4_REDADD         30
#define EE_MODE4_GREENADD       31
#define EE_MODE4_BLUEADD        32
#define EE_MODE4_WHITEADD       34
#define EE_STATEBYTEADD         36

#define EE_CHECKBYTEDATA        69

#define LOOPTIME        10

#define ADJ_THRESHOLD   5

#define TIMEOUT1S       100
#define TIMEOUT5S       500
#define TIMEOUT10s      1000
#define TIMEOUT100MS    10
#define TIMEOUT250MS    25

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    SPI1_Open(SPI1_DEFAULT);
    INTERRUPT_GlobalInterruptEnable();

    TMR2_SetInterruptHandler(LOOPDELAY_TimerISR);
    
    uint8_t red, green, blue, white = 0;
    uint8_t redMode1, greenMode1, blueMode1, whiteMode1 = 20;
    uint8_t redMode2, greenMode2, blueMode2, whiteMode2 = 255;
    uint8_t redMode3, greenMode3, blueMode3, whiteMode3 = 50;
    uint8_t redMode4, greenMode4, blueMode4, whiteMode4 = 0;
    uint8_t taster1Flag = 0;
    uint8_t taster2Flag = 0;
    uint8_t taster3Flag = 0;
    uint8_t taster4Flag = 0;    
    
    
    bool led1Blink = false;
    bool led2Blink = false;
    bool led3Blink = false;
    bool led4Blink = false;
    
    
    bool led1StateBlink = false;
    bool led2StateBlink = false;
    bool led3StateBlink = false;
    bool led4StateBlink = false;
    
    bool redAdj = false;
    bool greenAdj = false;
    bool blueAdj = false;
    bool whiteAdj = false;
    
    uint8_t timeout1s, timeout100ms = 0;
    uint16_t timeout5s = 0; 
    uint16_t timeout5sPressed1 = 0; 
    uint16_t timeout5sPressed2 = 0; 
    uint16_t timeout5sPressed3 = 0; 
    uint16_t timeout5sPressed4 = 0; 
    uint16_t timeout10s = 0; 
    uint8_t timeout500ms = 0;
    uint8_t timeout250ms = 0;    
    
    LED1_LAT = 0;
    LED2_LAT = 0;
    LED3_LAT = 0;
    LED4_LAT = 0;
    
    /*Statemachine Init*/
    typedef enum
    {
        MANUAL, T1, T2, T3, T4, T1Dummy, T2Dummy, T3Dummy, T4Dummy, 
        T1StateDummy, T2StateDummy, T3StateDummy, T4StateDummy
    }state_t;
    
    state_t state = MANUAL;    
    
    //=========================== Mode check start ============================//
    
    if(DATAEE_ReadByte(EE_MODE1CHECKBYTEADD) == EE_CHECKBYTEDATA)
    {
        redMode1 = DATAEE_ReadByte(EE_MODE1_REDADD);
        greenMode1 = DATAEE_ReadByte(EE_MODE1_GREENADD);
        blueMode1 = DATAEE_ReadByte(EE_MODE1_BLUEADD);
        whiteMode1 = DATAEE_ReadByte(EE_MODE1_WHITEADD);
    }
    
    if(DATAEE_ReadByte(EE_MODE2CHECKBYTEADD) == EE_CHECKBYTEDATA)
    {
        redMode2 = DATAEE_ReadByte(EE_MODE2_REDADD);
        greenMode2 = DATAEE_ReadByte(EE_MODE2_GREENADD);
        blueMode2 = DATAEE_ReadByte(EE_MODE2_BLUEADD);
        whiteMode2 = DATAEE_ReadByte(EE_MODE2_WHITEADD);
    }
    
    if(DATAEE_ReadByte(EE_MODE3CHECKBYTEADD) == EE_CHECKBYTEDATA)
    {
        redMode3 = DATAEE_ReadByte(EE_MODE3_REDADD);
        greenMode3 = DATAEE_ReadByte(EE_MODE3_GREENADD);
        blueMode3 = DATAEE_ReadByte(EE_MODE3_BLUEADD);
        whiteMode3 = DATAEE_ReadByte(EE_MODE3_WHITEADD);
    }
    
    if(DATAEE_ReadByte(EE_MODE4CHECKBYTEADD) == EE_CHECKBYTEDATA)
    {
        redMode4 = DATAEE_ReadByte(EE_MODE4_REDADD);
        greenMode4 = DATAEE_ReadByte(EE_MODE4_GREENADD);
        blueMode4 = DATAEE_ReadByte(EE_MODE4_BLUEADD);
        whiteMode4 = DATAEE_ReadByte(EE_MODE4_WHITEADD);
    }        
    
    //================= Mode check ends & State check starts ==================//
    
    if(DATAEE_ReadByte(EE_STATECHECKBYTEADD) == EE_CHECKBYTEDATA)
    {
        state = DATAEE_ReadByte(EE_STATEBYTEADD);
       
        if(state == 1 && (DATAEE_ReadByte(EE_MODE1CHECKBYTEADD) == EE_CHECKBYTEDATA))
        {
            LED1_LAT = 1;
            __delay_us(50);
            LED_WriteFull(redMode1, greenMode1, blueMode1, whiteMode1, LEDCOUNT);
        }
        else if (state == 1)
        {
            state = MANUAL;
        }        
        
        if(state == 2 && (DATAEE_ReadByte(EE_MODE2CHECKBYTEADD) == EE_CHECKBYTEDATA))
        {
            LED2_LAT = 1;
            __delay_us(50);
            LED_WriteFull(redMode2, greenMode2, blueMode2, whiteMode2, LEDCOUNT);
        }
        else if(state == 2)
        {
            state = MANUAL;
        }
        
        if(state == 3 && (DATAEE_ReadByte(EE_MODE3CHECKBYTEADD) == EE_CHECKBYTEDATA))
        {            
            LED3_LAT = 1;          
            __delay_us(50);
            LED_WriteFull(redMode3, greenMode3, blueMode3, whiteMode3, LEDCOUNT);
        }
        else if(state == 3)
        {
            state = MANUAL;
        }        
        
        if(state == 4 && (DATAEE_ReadByte(EE_MODE4CHECKBYTEADD) == EE_CHECKBYTEDATA))
        {
            LED4_LAT = 1;
            __delay_us(50);
            LED_WriteFull(redMode4, greenMode4, blueMode4, whiteMode4, LEDCOUNT);
        }        
        else if(state == 4)
        {
            state = MANUAL;
        }
    }
    //========================= Statecheck ending =============================//

    
    LOOPDELAY_Init(LOOPTIME);
    
    while (1)
    {
        taster1Flag = T1_PORT;
        taster2Flag = T2_PORT;
        taster3Flag = T3_PORT;
        taster4Flag = T4_PORT;
        
        ADCC_DischargeSampleCapacitor();
        red = map(ADCC_GetSingleConversion(POT1),0,4095,0,255);
        ADCC_DischargeSampleCapacitor();
        green = map(ADCC_GetSingleConversion(POT2),0,4095,0,255);
        ADCC_DischargeSampleCapacitor();
        blue = map(ADCC_GetSingleConversion(POT3),0,4095,0,255);
        ADCC_DischargeSampleCapacitor();
        white = map(ADCC_GetSingleConversion(POT4),0,4095,0,255);
        
        LOOPDELAY_Wait();
        
        switch(state)
        {
            case MANUAL:                
                              
                LED_WriteFull(red, green, blue, white, LEDCOUNT);
                
                __delay_us(50);
                
    //=========================== Check for Keypress ===========================//
                
                if(!T1_PORT && taster1Flag && !led1Blink && !led2Blink && !led3Blink && !led4Blink)          
                {
                    state = T1Dummy;    
                }                
                
                if(!T2_PORT && taster2Flag && !led1Blink && !led2Blink && !led3Blink && !led4Blink)
                {                                        
                    state = T2Dummy;    
                }                
                
                if(!T3_PORT && taster3Flag && !led1Blink && !led2Blink && !led3Blink && !led4Blink)
                {                    
                    state = T3Dummy;    
                }                
                if(!T4_PORT && taster4Flag && !led1Blink && !led2Blink && !led3Blink && !led4Blink)
                {                    
                    state = T4Dummy ;    
                }                
                
    //====================== Let those buttons flash for 10s ===================// 
                if((led1Blink || led2Blink || led3Blink || led4Blink) && (++timeout10s == TIMEOUT10s))
                {
                    timeout10s = 0;
                    
                    led1Blink = false;
                    led2Blink = false;
                    led3Blink = false;
                    led4Blink = false;
                }
                
                if(led1Blink && ++timeout500ms == TIMEOUT250MS)
                {
                    timeout500ms = 0;
                    LED1_LAT = !LED1_LAT;
                }
                
                if(led2Blink && ++timeout500ms == TIMEOUT250MS)
                {
                    timeout500ms = 0;
                    LED2_LAT = !LED2_LAT;
                }
                
                if(led3Blink && ++timeout500ms == TIMEOUT250MS)
                {
                    timeout500ms = 0;
                    LED3_LAT = !LED3_LAT;
                }
                
                if(led4Blink && ++timeout500ms == TIMEOUT250MS)
                {
                    timeout500ms = 0;
                    LED4_LAT = !LED4_LAT;
                }
    //Reset all LED's if not blinking                
                if(!(led1Blink || led2Blink || led3Blink || led4Blink))
                {
                    timeout500ms = 0;
                    
                    LED1_LAT = 0;
                    LED2_LAT = 0;
                    LED3_LAT = 0;
                    LED4_LAT = 0; 
                }
                
    //======= Check if a button is pressed while it blinks (mode programming)===/
                
                if(led1Blink && !T1_PORT && taster1Flag)
                {
                    redMode1 = red;
                    greenMode1 = green;
                    blueMode1 = blue;
                    whiteMode1 = white;
                    led1Blink = false;
                    DATAEE_WriteByte(EE_MODE1_BLUEADD, blueMode1);
                    DATAEE_WriteByte(EE_MODE1_GREENADD, greenMode1);
                    DATAEE_WriteByte(EE_MODE1_REDADD, redMode1);
                    DATAEE_WriteByte(EE_MODE1_WHITEADD, whiteMode1);
                    DATAEE_WriteByte(EE_MODE1CHECKBYTEADD, EE_CHECKBYTEDATA);
                }                
                
                if(led2Blink && !T2_PORT && taster2Flag)
                {
                    redMode2 = red;
                    greenMode2 = green;
                    blueMode2 = blue;
                    whiteMode2 = white;
                    led2Blink = false;
                    DATAEE_WriteByte(EE_MODE2_BLUEADD, blueMode2);
                    DATAEE_WriteByte(EE_MODE2_GREENADD, greenMode2);
                    DATAEE_WriteByte(EE_MODE2_REDADD, redMode2);
                    DATAEE_WriteByte(EE_MODE2_WHITEADD, whiteMode2);
                    DATAEE_WriteByte(EE_MODE2CHECKBYTEADD, EE_CHECKBYTEDATA);
                }                
                
                if(led3Blink && !T3_PORT && taster3Flag)
                {
                    redMode3 = red;
                    greenMode3 = green;
                    blueMode3 = blue;
                    whiteMode3 = white;
                    led3Blink = false;
                    DATAEE_WriteByte(EE_MODE3_BLUEADD, blueMode3);
                    DATAEE_WriteByte(EE_MODE3_GREENADD, greenMode3);
                    DATAEE_WriteByte(EE_MODE3_REDADD, redMode3);
                    DATAEE_WriteByte(EE_MODE3_WHITEADD, whiteMode3);
                    DATAEE_WriteByte(EE_MODE3CHECKBYTEADD, EE_CHECKBYTEDATA);                    
                }
                
                if(led4Blink && !T4_PORT && taster4Flag)
                {
                    redMode4 = red;
                    greenMode4 = green;
                    blueMode4 = blue;
                    whiteMode4 = white;
                    led4Blink = false;
                    DATAEE_WriteByte(EE_MODE4_BLUEADD, blueMode4);
                    DATAEE_WriteByte(EE_MODE4_GREENADD, greenMode4);
                    DATAEE_WriteByte(EE_MODE4_REDADD, redMode4);
                    DATAEE_WriteByte(EE_MODE4_WHITEADD, whiteMode4);
                    DATAEE_WriteByte(EE_MODE4CHECKBYTEADD, EE_CHECKBYTEDATA);    
                }                
                
    //==========================================================================//
                
                if(T1_PORT)
                {
                    timeout5sPressed1 = 0;
                }              
                
                if(T2_PORT)
                {
                    timeout5sPressed2 = 0;
                }                
                             
                if(T3_PORT)
                {
                    timeout5sPressed3 = 0;
                }                
                               
                if(T4_PORT)
                {
                    timeout5sPressed4 = 0;
                }
                
                break;           
                
    //========================== Case T1 Dummy =================================//
            case T1Dummy:
                
                if(T1_PORT)
                {
                    LED1_LAT = 1;
                    LED_WriteFull(redMode1, greenMode1, blueMode1, whiteMode1, LEDCOUNT);
                    state = T1;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T1_PORT && (++timeout5sPressed1 == TIMEOUT5S))
                {
                    timeout5sPressed1 = 0;
                    led1Blink = true;
                    state = MANUAL;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }                            
                
                break;
                
    //========================== Case T2 Dummy =====================================//
            case T2Dummy:
                
                if(T2_PORT)
                {
                    LED2_LAT = 1;
                    LED_WriteFull(redMode2, greenMode2, blueMode2, whiteMode2, LEDCOUNT);
                    state = T2;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T2_PORT && (++timeout5sPressed2 == TIMEOUT5S))
                {
                    timeout5sPressed2 = 0;
                    led2Blink = true;
                    state = MANUAL;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }                
                
                break;
    //========================== Case T3 Dummy =====================================//
            case T3Dummy:
                
                if(T3_PORT)
                {   
                    LED3_LAT = 1;
                    LED_WriteFull(redMode3, greenMode3, blueMode3, whiteMode3, LEDCOUNT);
                    state = T3;           
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte             
                }
                
                if(!T3_PORT && (++timeout5sPressed3 == TIMEOUT5S))
                {
                    timeout5sPressed3 = 0;
                    led3Blink = true;
                    state = MANUAL;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }                
                
                break;
                
    //========================== Case T4 Dummy =====================================//
            case T4Dummy:
                
                if(T4_PORT)
                {
                    LED4_LAT = 1;
                    LED_WriteFull(redMode4, greenMode4, blueMode4, whiteMode4, LEDCOUNT);
                    state = T4;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T4_PORT && (++timeout5sPressed4 == TIMEOUT5S))
                {
                    timeout5sPressed4 = 0;
                    led4Blink = true;
                    state = MANUAL;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                break;
    
    //======================= Case T1 State Dummy ============================//       
                
            case T1StateDummy:
                
                if(T1_PORT)
                {
                    LED1_LAT = 0;
                    state = MANUAL;
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T1_PORT && (++timeout5sPressed1 == TIMEOUT5S))
                {
                    timeout5sPressed1 = 0;
                    led1StateBlink = true;
                    state = T1; 
                }
                
                break;
                
    //======================= Case T2 State Dummy ============================//   
                
            case T2StateDummy:
                
                if(T2_PORT)
                {
                    LED2_LAT = 0;
                    state = MANUAL;
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T2_PORT && (++timeout5sPressed2 == TIMEOUT5S))
                {
                    timeout5sPressed2 = 0;
                    led2StateBlink = true;
                    state = T2; 
                }
                
                break;
                
    //======================= Case T3 State Dummy ============================//
                
            case T3StateDummy:
                
                if(T3_PORT)
                {
                    LED3_LAT = 0;
                    state = MANUAL;
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T3_PORT && (++timeout5sPressed3 == TIMEOUT5S))
                {
                    timeout5sPressed3 = 0;
                    led3StateBlink = true;
                    state = T3; 
                }
                
                break;
                
    //======================= Case T4 State Dummy ============================//            
                
            case T4StateDummy:
                
                if(T4_PORT)
                {
                    LED4_LAT = 0;
                    state = MANUAL;
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T4_PORT && (++timeout5sPressed4 == TIMEOUT5S))
                {
                    timeout5sPressed4 = 0;
                    led4StateBlink = true;
                    state = T4;
                }
                
                break;
                
    //========================== Case T1 =====================================//
                
            case T1:
                
                LED_WriteFull(redMode1,greenMode1,blueMode1, whiteMode1, LEDCOUNT);
                                
        //======================== T1 Adjusting ==============================//        
                
                if(led1StateBlink && (++timeout250ms == TIMEOUT250MS))
                {
                    timeout250ms = 0;
                    LED1_LAT = !LED1_LAT;
                }
                
                if(!T1_PORT && taster1Flag && !led1StateBlink)
                {
                    state = T1StateDummy;
                }
                
                if(!T1_PORT && taster1Flag && led1StateBlink)
                {
                    LED1_LAT = 1;
                    led1StateBlink = false;
                    redAdj = false;
                    greenAdj = false;
                    blueAdj = false;
                    whiteAdj = false;
                    redMode1 = red;
                    greenMode1 = green;
                    blueMode1 = blue;
                    whiteMode1 = white;
                    DATAEE_WriteByte(EE_MODE1_BLUEADD, blueMode1);
                    DATAEE_WriteByte(EE_MODE1_GREENADD, greenMode1);
                    DATAEE_WriteByte(EE_MODE1_REDADD, redMode1);
                    DATAEE_WriteByte(EE_MODE1_WHITEADD, whiteMode1);
                    DATAEE_WriteByte(EE_MODE1CHECKBYTEADD, EE_CHECKBYTEDATA);
                }
                
                if(led1StateBlink)
                {
                    if((red >= (redMode1 - ADJ_THRESHOLD) && red <= redMode1 + ADJ_THRESHOLD))
                    {
                        redAdj = true;
                    }
                    
                    if(redAdj)
                    {
                        redMode1 = red;
                    }
                    
                    if((white >= (whiteMode1 - ADJ_THRESHOLD) && white <= whiteMode1 + ADJ_THRESHOLD))
                    {
                        whiteAdj = true;
                    }
                    
                    if(whiteAdj)
                    {
                        whiteMode1 = white;
                    }
                    
                    if((green >= (greenMode1 - ADJ_THRESHOLD) && green <= greenMode1 + ADJ_THRESHOLD))
                    {
                       greenAdj = true; 
                    }
                    
                    if(greenAdj)
                    {
                        greenMode1 = green;
                    }
                    
                    if((blue >= (blueMode1 - ADJ_THRESHOLD) && blue <= blueMode1 + ADJ_THRESHOLD))
                    {
                        blueAdj = true;
                    }
                    
                    if(blueAdj)
                    {
                        blueMode1 = blue;
                    }
                }
                
        //======================== T1 Adjusting ends ==============================//      
                
                if(!T2_PORT && taster2Flag)
                {
                    LED1_LAT = 0;
                    LED2_LAT = 1;
                    LED_WriteFull(redMode2, greenMode2, blueMode2, whiteMode2, LEDCOUNT);
                    state = T2;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }                
                
                if(!T3_PORT && taster3Flag)
                {
                    LED1_LAT = 0;
                    LED3_LAT = 1;
                    LED_WriteFull(redMode3, greenMode3, blueMode3, whiteMode3, LEDCOUNT);
                    state = T3 ;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T4_PORT && taster4Flag)
                {
                    LED1_LAT = 0;
                    LED4_LAT = 1;
                    LED_WriteFull(redMode4, greenMode4, blueMode4, whiteMode4, LEDCOUNT);
                    state = T4 ;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                

                break;
                
    //========================== Case T2 =====================================//  
                
            case T2:
                
                LED_WriteFull(redMode2,greenMode2,blueMode2, whiteMode2, LEDCOUNT);
                                
        //======================== T2 Adjusting ==============================//        
                
                if(led2StateBlink && (++timeout250ms == TIMEOUT250MS))
                {
                    timeout250ms = 0;
                    LED2_LAT = !LED2_LAT;
                }
                
                if(!T2_PORT && taster2Flag && !led2StateBlink)
                {
                    state = T2StateDummy;
                }
                
                if(!T2_PORT && taster2Flag && led2StateBlink)
                {
                    LED2_LAT = 1;
                    led2StateBlink = false;
                    redAdj = false;
                    greenAdj = false;
                    blueAdj = false;
                    whiteAdj = false;
                    redMode2 = red;
                    greenMode2 = green;
                    blueMode2 = blue;
                    whiteMode2 = white;
                    DATAEE_WriteByte(EE_MODE2_BLUEADD, blueMode1);
                    DATAEE_WriteByte(EE_MODE2_GREENADD, greenMode1);
                    DATAEE_WriteByte(EE_MODE2_REDADD, redMode1);
                    DATAEE_WriteByte(EE_MODE2_WHITEADD, whiteMode1);
                    DATAEE_WriteByte(EE_MODE2CHECKBYTEADD, EE_CHECKBYTEDATA);
                }
                
                if(led2StateBlink)
                {
                    if((red >= (redMode2 - ADJ_THRESHOLD) && red <= redMode2 + ADJ_THRESHOLD))
                    {
                        redAdj = true;
                    }
                    
                    if(redAdj)
                    {
                        redMode2 = red;
                    }
                    
                    if((white >= (whiteMode2 - ADJ_THRESHOLD) && white <= whiteMode2 + ADJ_THRESHOLD))
                    {
                        whiteAdj = true;
                    }
                    
                    if(whiteAdj)
                    {
                        whiteMode2 = white;
                    }
                    
                    if((green >= (greenMode2 - ADJ_THRESHOLD) && green <= greenMode2 + ADJ_THRESHOLD))
                    {
                       greenAdj = true; 
                    }
                    
                    if(greenAdj)
                    {
                        greenMode2 = green;
                    }
                    
                    if((blue >= (blueMode2 - ADJ_THRESHOLD) && blue <= blueMode2 + ADJ_THRESHOLD))
                    {
                        blueAdj = true;
                    }
                    
                    if(blueAdj)
                    {
                        blueMode2 = blue;
                    }
                }
                
        //======================== T2 Adjusting ends ==============================//
                
                
                if(!T1_PORT && taster1Flag)
                {
                    LED2_LAT = 0;
                    LED1_LAT = 1;
                    LED_WriteFull(redMode1, greenMode1, blueMode1, whiteMode1, LEDCOUNT);
                    state = T1;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                
                if(!T3_PORT && taster3Flag)
                {
                    LED2_LAT = 0;
                    LED3_LAT = 1;
                    LED_WriteFull(redMode3, greenMode3, blueMode3, whiteMode3, LEDCOUNT);
                    state = T3 ;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                if(!T4_PORT && taster4Flag)
                {
                    LED2_LAT = 0;
                    LED4_LAT = 1;
                    LED_WriteFull(redMode4, greenMode4, blueMode4, whiteMode4, LEDCOUNT);
                    state = T4 ;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                
                break;
                
    //========================== Case T3 =====================================//            
                
            case T3:
                
                LED_WriteFull(redMode3,greenMode3,blueMode3, whiteMode3, LEDCOUNT);
                                
        //======================== T3 Adjusting ==============================//        
                
                if(led3StateBlink && (++timeout250ms == TIMEOUT250MS))
                {
                    timeout250ms = 0;
                    LED3_LAT = !LED3_LAT;
                }
                
                if(!T3_PORT && taster3Flag && !led3StateBlink)
                {
                    state = T3StateDummy;
                }
                
                if(!T3_PORT && taster3Flag && led3StateBlink)
                {
                    LED3_LAT = 1;
                    led3StateBlink = false;
                    redAdj = false;
                    greenAdj = false;
                    blueAdj = false;
                    whiteAdj = false;
                    redMode3 = red;
                    greenMode3 = green;
                    blueMode3 = blue;
                    whiteMode3 = white;
                    DATAEE_WriteByte(EE_MODE3_BLUEADD, blueMode1);
                    DATAEE_WriteByte(EE_MODE3_GREENADD, greenMode1);
                    DATAEE_WriteByte(EE_MODE3_REDADD, redMode1);
                    DATAEE_WriteByte(EE_MODE3_WHITEADD, whiteMode1);
                    DATAEE_WriteByte(EE_MODE3CHECKBYTEADD, EE_CHECKBYTEDATA);
                }
                taster3Flag = T3_PORT;
                
                if(led3StateBlink)
                {
                    if((red >= (redMode3 - ADJ_THRESHOLD) && red <= redMode3 + ADJ_THRESHOLD))
                    {
                        redAdj = true;
                    }
                    
                    if(redAdj)
                    {
                        redMode3 = red;
                    }
                    
                    if((white >= (whiteMode3 - ADJ_THRESHOLD) && white <= whiteMode3 + ADJ_THRESHOLD))
                    {
                        whiteAdj = true;
                    }
                    
                    if(whiteAdj)
                    {
                        whiteMode3 = white;
                    }
                    
                    if((green >= (greenMode3 - ADJ_THRESHOLD) && green <= greenMode3 + ADJ_THRESHOLD))
                    {
                       greenAdj = true; 
                    }
                    
                    if(greenAdj)
                    {
                        greenMode3 = green;
                    }
                    
                    if((blue >= (blueMode3 - ADJ_THRESHOLD) && blue <= blueMode3 + ADJ_THRESHOLD))
                    {
                        blueAdj = true;
                    }
                    
                    if(blueAdj)
                    {
                        blueMode3 = blue;
                    }
                }
                
        //======================== T3 Adjusting ends ==============================//                
                
                if(!T1_PORT && taster1Flag)
                {
                    LED3_LAT = 0;
                    LED1_LAT = 1;
                    LED_WriteFull(redMode1, greenMode1, blueMode1, whiteMode1, LEDCOUNT);
                    state = T1;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                
                if(!T2_PORT && taster2Flag)
                {
                    LED3_LAT = 0;
                    LED2_LAT = 1;
                    LED_WriteFull(redMode2, greenMode2, blueMode2, whiteMode2, LEDCOUNT);
                    state = T2;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                
                if(!T4_PORT && taster4Flag)
                {
                    LED3_LAT = 0;
                    LED4_LAT = 1;
                    LED_WriteFull(redMode4, greenMode4, blueMode4, whiteMode4, LEDCOUNT);
                    state = T4 ;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                
    //========================== Case T4 =====================================//    
                
            case T4:
                
                LED_WriteFull(redMode4,greenMode4,blueMode4, whiteMode4, LEDCOUNT);
                
        //======================== T4 Adjusting ==============================//        
                
                if(led4StateBlink && (++timeout250ms == TIMEOUT250MS))
                {
                    timeout250ms = 0;
                    LED4_LAT = !LED4_LAT;
                }
                
                if(!T4_PORT && taster4Flag && !led4StateBlink)
                {
                    state = T4StateDummy;
                }
                
                if(!T4_PORT && taster4Flag && led4StateBlink)
                {
                    LED4_LAT = 1;
                    led4StateBlink = false;
                    redAdj = false;
                    greenAdj = false;
                    blueAdj = false;
                    whiteAdj = false;
                    redMode4 = red;
                    greenMode4 = green;
                    blueMode4 = blue;
                    whiteMode4 = white;
                    DATAEE_WriteByte(EE_MODE4_BLUEADD, blueMode1);
                    DATAEE_WriteByte(EE_MODE4_GREENADD, greenMode1);
                    DATAEE_WriteByte(EE_MODE4_REDADD, redMode1);
                    DATAEE_WriteByte(EE_MODE4_WHITEADD, whiteMode1);
                    DATAEE_WriteByte(EE_MODE4CHECKBYTEADD, EE_CHECKBYTEDATA);
                }
                
                if(led4StateBlink)
                {
                    if((red >= (redMode4 - ADJ_THRESHOLD) && red <= redMode4 + ADJ_THRESHOLD))
                    {
                        redAdj = true;
                    }
                    
                    if(redAdj)
                    {
                        redMode4 = red;
                    }
                    
                    if((white >= (whiteMode4 - ADJ_THRESHOLD) && white <= whiteMode4 + ADJ_THRESHOLD))
                    {
                        whiteAdj = true;
                    }
                    
                    if(whiteAdj)
                    {
                        whiteMode4 = white;
                    }
                    
                    if((green >= (greenMode4 - ADJ_THRESHOLD) && green <= greenMode4 + ADJ_THRESHOLD))
                    {
                       greenAdj = true; 
                    }
                    
                    if(greenAdj)
                    {
                        greenMode4 = green;
                    }
                    
                    if((blue >= (blueMode4 - ADJ_THRESHOLD) && blue <= blueMode4 + ADJ_THRESHOLD))
                    {
                        blueAdj = true;
                    }
                    
                    if(blueAdj)
                    {
                        blueMode4 = blue;
                    }
                }
                
        //======================== T4 Adjusting ends ==============================//
                
                
                if(!T1_PORT && taster1Flag)
                {
                    LED4_LAT = 0;
                    LED1_LAT = 1;
                    state = T1;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                
                if(!T2_PORT && taster2Flag)
                {
                    LED4_LAT = 0;
                    LED2_LAT = 1;
                    LED_WriteFull(redMode2, greenMode2, blueMode2, whiteMode2, LEDCOUNT);
                    state = T2;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                
                if(!T3_PORT && taster3Flag)
                {
                    LED4_LAT = 0;
                    LED3_LAT = 1;
                    LED_WriteFull(redMode3, greenMode3, blueMode3, whiteMode3, LEDCOUNT);
                    state = T3 ;    
                    DATAEE_WriteByte(EE_STATEBYTEADD, state);                       //Update EEPROM
                    DATAEE_WriteByte(EE_STATECHECKBYTEADD, EE_CHECKBYTEDATA);       //Update EEPROM checkbyte
                }
                
                break;
        }               
    }
}