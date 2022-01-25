/* 
 * File:   Loopdelay.h
 * Author: brebej
 *
 * Created on 22. Januar 2021, 08:12
 */

#ifndef LOOPDELAY_H
#define	LOOPDELAY_H

#include <xc.h>
#include "mcc_generated_files/mcc.h"

void LOOPDELAY_TimerISR(void);
void LOOPDELAY_Wait(void);
void LOOPDELAY_Init(uint16_t newLoopTimeMS);

#endif	/* LOOPDELAY_H */