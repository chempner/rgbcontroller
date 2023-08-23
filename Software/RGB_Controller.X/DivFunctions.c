#include "DivFunctions.h"

void WS2812B_Write(uint8_t R, uint8_t G, uint8_t B)
{    
    ws_send_byte(G);    
    ws_send_byte(R);    
    ws_send_byte(B);
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void onePulse(void)
{
    IO_RB4_LAT = 1;
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    IO_RB4_LAT = 0;    
    NOP();
    NOP();
    NOP();
}

void zeroPulse(void)
{
    IO_RB4_LAT = 1;   
    NOP();
    NOP();
    NOP();
    IO_RB4_LAT = 0;
//    NOP();
//    NOP();
//    NOP();
//    NOP();
//    NOP();
//    NOP();
//    NOP();
//    NOP();
//    NOP();
//    NOP();
}
void ws_send_byte(uint8_t K)
{
    if(K & 0b10000000) {onePulse();}
    else {zeroPulse();}
    
    if(K & 0b01000000) {onePulse();}
    else {zeroPulse();}
    
    if(K & 0b00100000) {onePulse();}
    else {zeroPulse();}
    
    if(K & 0b00010000) {onePulse();}
    else {zeroPulse();}
    
    if(K & 0b00001000) {onePulse();}
    else {zeroPulse();}
    
    if(K & 0b00000100) {onePulse();}
    else {zeroPulse();}
    
    if(K & 0b00000010) {onePulse();}
    else {zeroPulse();}
    
    if(K & 0b00000001) {onePulse();}
    else {zeroPulse();}
}

void LED_WriteFull(uint8_t red, uint8_t green, uint8_t blue, uint24_t ledcount)
{
    for(uint24_t x = 0; x <= (15); x++)
    {
        for(uint8_t i=0; i <= 20; i++)
        {
            WS2812B_Write(red, green, blue);
        }
//        __delay_us(300);
    }
    
}