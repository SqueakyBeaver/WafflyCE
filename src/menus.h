#ifndef MENUS_H
#define MENUS_H 1

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

typedef struct {
    uint8_t y_coord;
    char message[20];
} menu_choice;

int8_t menu_Main();
#endif
