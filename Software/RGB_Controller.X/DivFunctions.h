//
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DIVFUNCTIONS_H
#define	DIVFUNCTIONS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/mcc.h"




#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

void c_WS2812B_Write(uint8_t R, uint8_t G, uint8_t B, uint8_t W);

void onePulse(void);

void zeroPulse(void);

void ws_send_byte(uint8_t K);