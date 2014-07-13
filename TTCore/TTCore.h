#ifndef __TTCORE__
#define __TTCORE__

#include <stdint.h>

// Helper defines
#define SCREENWIDE 10
#define SCREENHIGH 20
#define BUTTONPORT PINC
#define LButtonPin PC0
#define UButtonPin PC1
#define DButtonPin PC2
#define RButtonPin PC3

// These SPI defines are specific to the PDIP m328p
// and may need changed for your device
#define DDR_SPI DDRB
#define DD_MOSI PB3
#define DD_MISO PB4
#define DD_SCK  PB5
#define DD_SS   PB2


// Library function types

typedef struct {
    uint8_t frameWaiting;
    uint8_t frameLocked;
    uint8_t screen[SCREENHIGH][SCREENWIDE];
} TTContext;

// Library function prototypes
TTContext* makeTTContext(void);				// Return an initialised TTContext
                                            // Additionally will init hardware.

void freeTTContext(TTContext *ctxt);        // Free a finished TTContext. BEWARE:
                                            // Remember to disconnect any interrupts
                                            // relying on this context.

uint8_t writeScreen(TTContext *ctxt);       // Write the screen to hardware

uint8_t getLButton(void);   // Helpers to automatically get Left/Right/Up/Down button states
uint8_t getRButton(void);
uint8_t getUButton(void);
uint8_t getDButton(void);

void waitForFrame(TTContext* ctxt);     // Waits for the current frame to have been written

#endif
