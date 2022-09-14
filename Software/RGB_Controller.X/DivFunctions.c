#include "DivFunctions.h"

void WS2812B_Write(uint8_t R, uint8_t G, uint8_t B, uint8_t W)
{    
    ws_send_byte(G);
    ws_send_byte(R);
    ws_send_byte(B);
//    ws_send_byte(W);
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void onePulse(void)
{
    SPI1_ExchangeByte(0xF0);
}

void zeroPulse(void)
{
    SPI1_ExchangeByte(0xC0);
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

void LED_WriteFull(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint24_t ledcount)
{
    for(uint24_t i=0; i <= ledcount; i++)
    {
        WS2812B_Write(red, green, blue, white);
    }
}