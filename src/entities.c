#include "entities.h"

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

player_t player = {Waffle, Waffle_height, Waffle_width, 20, 30, 0, 5, false, 0};

void UpdateKeyboard() {
    // Update kb_Data
    kb_Scan();

    player.m_dir = 0;
    player.m_sprite = Waffle;

    // Turn upwards
    if (kb_KeyUp && player.m_y > 0) {
        player.m_dir = -1;
        player.m_sprite = WaffleUp;
    }
    // Turn downwards
    if (kb_KeyDown && player.m_y < 240 - player.m_spriteHeight) {
        player.m_dir = 1;
        player.m_sprite = WaffleDown;
    }
    // Speed up
    if (kb_KeyRight && player.m_acceleration < 10) {
        ++player.m_acceleration;
    }
    // Slow down
    if (kb_KeyLeft && player.m_acceleration > 1) {
        --player.m_acceleration;
    }
    // If both the up and down keys are pressed,
    // do not turn
    if (kb_KeyUp && kb_KeyDown) {
        player.m_dir = 0;
    }
}

void UpdatePlayer() {
    // Update the player position
    player.m_x += player.m_acceleration;
    player.m_y += player.m_dir * 2;

    // Looping, I guess you would say
    if (player.m_x + player.m_spriteWidth > 280) {
        player.m_x = 0;
    }
}

void Draw() {
    // Fill the drawing area with the background color, and clear the side bar
    gfx_ZeroScreen();
    gfx_FillRectangle_NoClip(0, 0, 280, 240);

    gfx_SetTextXY(280, 20);
    gfx_PrintInt(player.m_dir, 3);

    // Draw the player's sprite
    gfx_TransparentSprite_NoClip(player.m_sprite, player.m_x, player.m_y);

    gfx_SwapDraw();
}
