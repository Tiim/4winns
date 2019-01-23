#include "output.h"

#define FIELD_HEIGHT 30
#define FIELD_WIDTH 14

#define INVERT_ROW(row) (ROWS - (row))

char getX(char x) {
  return 4 * getCol(x)+3;
}
char getY(char y) {
  return 2 * (ROWS - (getRow(y)));
}
uint16_t colorPlayer(chip p, uint16_t emptyColor) {
  uint16_t color = emptyColor;
  if (p == player1) color = COLOR_P1;
  if (p == player2) color = COLOR_P2;
  return color;
}

void render(struct match4* game, RGBmatrixPanel* matrix) {
  matrix->drawRect(0,0, 32, 16, colorPlayer(game->winner, GREEN_D));
  matrix->drawRect(1,1, 30, 14, GREEN_D);
  for(int i = 0; i < FIELDS; i++) {
    chip p = game->mainfield.field[i];
    
    char x = 4 * getCol(i)+3;
    char y = 2 * INVERT_ROW(getRow(i));
    
    matrix->drawRect(x, y, 2, 2, colorPlayer(p, BLACK));
  }
  
  matrix->drawRect(getX(game->col), 0, 2, 2, colorPlayer(game->isPlayer1? player1: player2, BLACK));
   
  
}
