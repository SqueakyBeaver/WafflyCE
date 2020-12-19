#include "play.h"

// Include the sprites header file
#include "gfx/gfx.h"
#include "player.h"

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
  gfx_SetClipRegion(0, 0, 320, 200);
  gfx_SetColor(4);

  do {
    // Update kb_Data
    kb_Scan();

    player.m_dir = 0;
    player.m_sprite = Waffle;

    if ((kb_Data[7] & kb_Up) && player.m_y > 0) {
      player.m_dir = -1;
      player.m_sprite = WaffleUp;
    }
    if ((kb_Data[7] & kb_Down) && player.m_y < 200 - player.m_spriteHeight) {
      player.m_dir = 1;
      player.m_sprite = WaffleDown;
    }
    if ((kb_Data[7] & kb_Right) && player.m_acceleration < 10) {
      ++player.m_acceleration;
    }
    if ((kb_Data[7] & kb_Left) && player.m_acceleration > 1) {
      --player.m_acceleration;
    }

    // Update the player position
    player.m_x += player.m_acceleration;
    player.m_y += player.m_dir * 2;

    if (player.m_x + player.m_spriteWidth > 320) {
      player.m_x = 0;
    }
    /*
    // I already did this and I forgot how I was going to do game mechanics,
    // but I am leaving this here in case I want it again
    if (player.m_dir == -1 && player.m_y < 0) {
      player.m_y = 200 - player.m_spriteHeight;
    }
    if (player.m_dir == 1 && player.m_y + player.m_spriteHeight > 200) {
      player.m_y = 0;
    }
    */
    // Fill the drawing area with the background color, and clear the bottom bar
    gfx_ZeroScreen();
    gfx_FillRectangle(0, 0, 320, 200);

    gfx_SetTextXY(280, 20);
    gfx_PrintInt(player.m_dir, 3);

    // Draw the player's sprite
    gfx_RLETSprite_NoClip(player.m_sprite, player.m_x, player.m_y);

    gfx_SwapDraw();
  } while (!(kb_Data[6] & kb_Clear));

  gfx_SetClipRegion(0, 0, 320, 240);
}
