#ifndef PLAY_H
#define PLAY_H 1

#include <stddef.h>
#include <stdint.h>

void play_Main();

typedef struct {
  int8_t x;
  int8_t y;
} increment_t;

typedef struct {
  uint24_t x;
  int8_t y;
} waffle_t;

#endif
