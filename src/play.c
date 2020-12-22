#include "play.h"

// Include the sprites header file
#include "entities.h"
#include "gfx/gfx.h"

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Other headers */
#include <graphx.h>
#include <keypadc.h>

void play_Main() {
    // Set graphics stuff
    gfx_SetTransparentColor(1);
    gfx_SetTextScale(1, 1);
    gfx_SetColor(4);

    do {
        UpdateKeyboard();
        UpdatePlayer();
        Draw();
    } while (!(kb_Data[6] & kb_Clear));
}
