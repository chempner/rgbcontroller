#include "Loopdelay.h"

#define MAX_LOOP_DELAY_MS 10000

static volatile uint16_t loopTimeCnt = 0;

static uint16_t loopTimeMS = 0;

void LOOPDELAY_TimerISR(void)
{
    if(loopTimeCnt != MAX_LOOP_DELAY_MS)
    {
        loopTimeCnt += 1;
    }
}

void LOOPDELAY_Wait(void)
{
    while(loopTimeCnt < loopTimeMS);
    loopTimeCnt = 0;
}

void LOOPDELAY_Init(uint16_t newLoopTimeMS)
{
    loopTimeMS = newLoopTimeMS;
}