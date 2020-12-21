#ifndef PLAYER_H
#define PLAYER_H 1

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Other headers */
#include <graphx.h>
#include <keypadc.h>

typedef struct {
  gfx_sprite_t *m_sprite;
  uint8_t m_spriteHeight;
  uint8_t m_spriteWidth;
  uint24_t m_x;
  uint8_t m_y;
  int8_t m_dir;
  int8_t m_acceleration;
  bool m_shooting;
  uint8_t m_bulletCount;
} player_t;

extern player_t player;

#endif
