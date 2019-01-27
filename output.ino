#include "output.h"

#define FIELD_HEIGHT 30
#define FIELD_WIDTH 14

#define INVERT_ROW(row) (ROWS - (row))

uint16_t lineColor = GREEN_D;

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
  matrix->drawRect(1,1, 30, 14, colorPlayer(game->winner, GREEN_D));  

  
  for(int i = 0; i < FIELDS; i++) {
    chip p = game->mainfield.field[i];
    
    char x = 4 * getCol(i)+3;
    char y = 2 * INVERT_ROW(getRow(i));

    matrix->drawRect(x, y, 2, 2, colorPlayer(p, BLACK));
    if(game->winner != empty) {
      if((signed char)i==game->mainfield.winningChipPos[0]||(signed char)i==game->mainfield.winningChipPos[1]||(signed char)i==game->mainfield.winningChipPos[2]||(signed char)i==game->mainfield.winningChipPos[3]) {
        matrix->drawRect(x, y, 2, 2, YELLOW);
      }
    }
}

  if(game->winner == empty) {
    matrix->drawRect(getX(game->col), 0, 2, 2, colorPlayer(game->isPlayer1? player1: player2, BLACK));
  }
}

void renderTurn(struct match4* game, RGBmatrixPanel* matrix, long t, char pos, chip player) {
  
  long offsettime = t;
  int offset = 0;
 
  char x = 4 * getCol(pos)+3;
  char y = 2 * INVERT_ROW(getRow(pos));

  while(offset<=(y-2)) {  

    if(millis()-offsettime>=80) {
      offset+=1;
      offsettime = millis();
    }

    matrix->drawLine(x, y+1, x, 2, colorPlayer(player,GREEN_D));
    matrix->drawLine(x+1, y+1, x+1, 2, colorPlayer(player,GREEN_D));

    matrix->drawLine(x, y+1, x, (2+offset), BLACK);
    matrix->drawLine(x+1, y+1, x+1, (2+offset), BLACK);
    
    if(millis()-t>=300&&(y-2)!=0) {
      matrix->drawLine(x, 2, x, (2+(offset-3)), BLACK);
      matrix->drawLine(x+1, 2, x+1, (2+(offset-3)), BLACK);
    }
    
    matrix->drawRect(0,0, 32, 16, colorPlayer(game->winner, GREEN_D));
    matrix->drawRect(1,1, 30, 14, GREEN_D); 

    matrix->swapBuffers(false);
  }
}

void renderWin(struct match4* game, RGBmatrixPanel* matrix) {

}