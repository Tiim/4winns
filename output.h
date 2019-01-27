#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <RGBmatrixPanel.h>
#include "logic.h"

// https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html

#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define RED_D    0x2801
#define GREEN    0x07E0
#define GREEN_D  0x0140
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

#define COLOR_P1 RED
#define COLOR_P2 BLUE

void render(struct match4* game, RGBmatrixPanel* matrix);
void renderTurn(struct match4* game, RGBmatrixPanel* matrix, long t, char pos, chip player);
void renderWin(struct match4* game, RGBmatrixPanel* matrix);

#endif
