#include "menus.h"

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

// I really don't want to write this a lot
#define CHOICE_STR_X_COORD(str) 120 + ((80 - gfx_GetStringWidth(str)) / 2)

/* This should always be called after gfx_Begin() in main */
int8_t menu_Main() {
  // The index of the selection cursor
  int8_t cursor_index = 0;
  // Menu items
  menu_choice choices[5] = {{95, "Play"},
                            {120, "Settings"},
                            {145, "About"},
                            {170, "Credits"},
                            {195, "Quit"}};

  // Just some variables to help with key presses
  bool up_prev, down_prev;
  kb_key_t arrows;

  gfx_SetTextFGColor(17);
  gfx_SetPalette(global_palette, sizeof_global_palette, 0);
  gfx_SetTransparentColor(1);
  do {
    gfx_FillScreen(4);

    /* Scan the keypad to update kb_Data */
    kb_Scan();

    /* Get the arrow key statuses */
    arrows = kb_Data[7];

    gfx_SetTextFGColor(7);
    gfx_SetTextScale(2, 2);
    gfx_PrintStringXY("Waffly CE",
                      (LCD_WIDTH - gfx_GetStringWidth("Waffly CE")) / 2, 40);
    gfx_SetTextScale(1, 1);

    // Choice words color
     gfx_SetTextFGColor(5);
    for (int8_t i = 0; i < 5; ++i) {
      // gfx_Rectangle(120, choices[i].y_coord - 5, 80, 20);
      gfx_PrintStringXY(choices[i].message,
                        CHOICE_STR_X_COORD(choices[i].message),
                        choices[i].y_coord);
    }

    // Cursor Color
    gfx_SetColor(6);
    gfx_Rectangle(120 - 2, choices[cursor_index].y_coord - 7, 80 + 4, 20 + 4);

    if ((arrows & kb_Up) && !up_prev) {
      --cursor_index;
      if (cursor_index < 0) {
        cursor_index = 4;
      }
    }

    if ((arrows & kb_Down) && !down_prev) {
      ++cursor_index;
      if (cursor_index > 4) {
        cursor_index = 0;
      }
    }

    up_prev = arrows & kb_Up;
    down_prev = arrows & kb_Down;

    gfx_SwapDraw();
  } while (!(kb_Data[6] & kb_Enter));

  return cursor_index;
}
