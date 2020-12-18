#include "play.h"

// Include the sprites header file
#include "gfx/gfx.h"

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Other headers */
#include <graphx.h>
#include <keypadc.h>

void play_Main() {
  // bool exit = false;

  gfx_sprite_t *waffleRotate = gfx_MallocSprite(Waffle_width, Waffle_height);

  uint8_t rotationDegree = 0;

  uint8_t acceleration = 0;

  // Set graphics stuff
  gfx_SetTransparentColor(0);
  gfx_SetTextScale(1, 1);

  // Position of the waffle
  waffle_t wafflePos = {20, 120};

  // increment vector (polar stuff was being.. annoying)
  // increment_t increment = {0, 0};

  do {
    // Update kb_Data

    if ((kb_Data[7] & kb_Right)) {
      rotationDegree += 2;
    }
    if ((kb_Data[7] & kb_Left)) {
      rotationDegree -= 2;
    }

    if ((kb_Data[7] & kb_Up) && acceleration < 5) {
      ++acceleration;
    }
    if ((kb_Data[7] & kb_Down) && acceleration > 0) {
      --acceleration;
    }

    wafflePos.x += acceleration * sin(rotationDegree * 360 / 256);
    wafflePos.y += acceleration * cos(rotationDegree * 360 / 256);
    kb_Scan();

    // Fill the screen so we don't have weird stuff
    gfx_FillScreen(4);

    gfx_SetTextXY(280, 20);
    gfx_PrintUInt(rotationDegree, 3);

    // Rotate the waffle
    gfx_RotateSprite(Waffle, waffleRotate, rotationDegree);

    // Draw the waffle and it's attached sprites
    gfx_TransparentSprite_NoClip(waffleRotate, wafflePos.x,
                                 wafflePos.y /*, rotationDegree, 64*/);


    gfx_SwapDraw();
  } while (!(kb_Data[6] & kb_Clear));
}
