/*
 *--------------------------------------
 * Program Name:
 * Author:
 * License:
 * Description:
 *--------------------------------------
 */

/* Screen width (because I forget sometimes):
     ______________320______________
    |                               |
    |                               |
    |                               | 240
    |                               |
    |                               |
    |_______________________________|
*/

#include "gfx/gfx.h" // For the palette
#include "menus.h"
#include "play.h"

// Keep these headers
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

// Standard headers
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Other headers
#include <graphx.h>
#include <keypadc.h>

//#define DEBUG 1
#ifdef DEBUG
#include <debug.h>
#endif

// Some macros for readability
#define PLAY 0
#define SETTINGS 1
#define ABOUT 2
#define CREDITS 3
#define QUIT 4

int main(void) {
    gfx_Begin();
    gfx_SetDrawBuffer();

    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(0);

    // The user has not pressed quit
    bool running = true;

    while (running) {
        int8_t choice = menu_Main();
        switch (choice) {
        case PLAY:
            play_Main();
            break;

        case SETTINGS:
            // menu_Settings();
            break;

        case ABOUT:
            // menu_About();
            break;

        case CREDITS:
            // menu_Credits();
            break;

        case QUIT:
            running = false;
            break;

        default:
            // If this is triggered, idk man
            break;
        }
        choice = -1;
    }

    gfx_End();

    return 0;
}
