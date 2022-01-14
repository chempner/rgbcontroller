#include "DivFunctions.h"

void c_WS2812B_Write(uint8_t R, uint8_t G, uint8_t B, uint8_t W)
{
    ws_send_byte(R);
    ws_send_byte(G);
    ws_send_byte(B);
    ws_send_byte(W);
}

void onePulse(void)
{
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 1;
ARGB_LAT= 0;
}

void zeroPulse(void)
{
ARGB_LAT= 1;
ARGB_LAT= 0;
}


//void onePulse(void)
//{
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//}

//void zeroPulse(void)
//{
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 1;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//    ARGB_LAT = 0;
//}

void ws_send_byte(unsigned char K)
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