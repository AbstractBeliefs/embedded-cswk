/*
 * TTCore.c
 *
 * Created: 28/02/2014 01:10:42
 *  Author: Gareth
 */ 

#include "TTCore.h"

#include <stdlib.h>
#include <string.h>
#include <avr/io.h>

TTContext* makeTTContext(void){     // Allocate and initialise a screen context
    // Get a screen context
    TTContext* ctxt = malloc(sizeof(TTContext));
    if (!ctxt) { return ctxt; }		    // Check to see if we were able to allocate mem
    
    // Initialise the variables
    memset(ctxt->screen, 0, SCREENHIGH*SCREENWIDE);     // Clear screen
    ctxt->frameWaiting = 0;                             // There's no unwritten frame
    ctxt->frameLocked = 0;                              // Frame isn't being written
	
    // Set button pins as inputs, and enable internal pullups
    DDRC &= 0x11110000;     // PC0-3 as inputs
    PORTC |= 0x11110000;    // PC0-3 pullup enable
    
    // Prepare SPI
    DDR_SPI |= _BV(DD_MOSI)|_BV(DD_SCK)|_BV(DD_SS);     // MOSI, SCK, SS as outputs
    SPCR = (1<<SPE)|(1<<MSTR);                          // Enable SPI, Master, CLK/4
    
    // Return our context
    return ctxt;
}

void freeTTContext(TTContext* ctxt){    // Free an old screen context
    free(ctxt);
}
	
uint8_t writeScreen(TTContext* ctxt){   // Write a context's screen to hardware
    // Write process:
    //  1) check if there is a frame waiting
    //  2) if there is, lock ctxt->frameLocked
    //  3) write frame
    //  4) release lock
    //  5) unset ctxt->frameWaiting
    if (ctxt->frameWaiting){
        return 0;
    }
    return 0;
}


// The following functions have "inverted" returns as the physical inputs are active-low
// These functions return active-high, which is what is most obvious
uint8_t getLButton(void){       // Return the state of the L Button
    return ~(BUTTONPORT & _BV(LButtonPin));
}
uint8_t getRButton(void){       // Return the state of the R Button
    return ~(BUTTONPORT & _BV(RButtonPin));
}
uint8_t getUButton(void){       // Return the state of the U Button
    return ~(BUTTONPORT & _BV(UButtonPin));
}
uint8_t getDButton(void){       // Return the state of the D Button
    return ~(BUTTONPORT & _BV(DButtonPin));
}

void waitForFrame(TTContext* ctxt){
    while (ctxt->frameWaiting) {}
    return;
}
