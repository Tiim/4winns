#include "logic.h"

// inserts a chip on the given column
// returns chip position or -1 if no chip could be placed
char insertChip(chip player, struct gamefield* game, int collumn) {
    while(game->field[collumn] != empty) {
        collumn += COLS;
        if(collumn >= FIELDS) {
            return -1;
        }
    }
    
    game->field[collumn] = player;
    return collumn;
}

inline int getCol(int field) {
  return field % COLS;
}

inline int getRow(int field) {
  return field / COLS;
}

// return the field left from the given field
// or -1 if no field available
inline int getLeft(int field) {
  int col = getCol(field);
  if (col == 0) return -1; //Check left edge
  else return field - 1;
}

inline int getRight(int field) {
  int col = getCol(field);
  if (col == COLS - 1) return -1; //Check right edge
  else return field + 1;
}

inline int getDown(int field) {
  int n = field - COLS;
  if (n < 0) return -1; //Check bottom edge
  else return n;
}

inline int getDiagonalLeftDown(int field) {
  int col = getCol(field);
  if (col == 0) return -1; //check left edge
  int n = field - COLS -1;
  if (n < 0) return -1; //check bottom edge
  return n;
}

inline int getDiagonalLeftUp(int field) {
  int col = getCol(field);
  if (col == 0) return -1; //check left edge
  int n = field + COLS -1;
  if (n <= 0) return -1; //check top edge
  return n;
}

inline int getDiagonalRightDown(int field) {
  int col = getCol(field);
  if (col == COLS - 1) return -1; //check right edge
  int n = field -COLS +1;
  if (n < 0) return -1; //check bottom edge
  return n;
}

inline int getDiagonalRightUp(int field) {
  int col = getCol(field);
  if (col == COLS - 1) return -1; //check right edge
  int n = field + COLS +1;
  if (n <= 0) return -1; //check top edge
  return n;
}




// returns true if current move was a win
bool checkWin(struct gamefield* game, int lastCoin) {
  chip p = game->field[lastCoin];
  int counter = 0;
  game->winningChipPos[counter] = lastCoin;
  
  //check right side
  int x = 1;
  int current = lastCoin;
  for(int i = 0; i < WINNING_NR; i++) {
    current = getRight(current);
    if (current == -1) break;
    if (game->field[current] == p){ 
      counter++;
      game->winningChipPos[counter] = current;
      x++;
    }
    else break;
  }
  
  //check left side
  current = lastCoin;
  for(int i = 0; i < WINNING_NR; i++) {
    current = getLeft(current);
    if (current == -1) break;
    if (game->field[current] == p){ 
      counter++;
      game->winningChipPos[counter] = current;
      x++;
    }
    else break;
  }
  if (x >= WINNING_NR) return true;
  
  //check down
  x = 1;
  counter = 0;
  current = lastCoin;
  for(int i = 0; i < WINNING_NR; i++) {
    current = getDown(current);
    if (current == -1) break;
    if (game->field[current] == p){ 
      counter++;
      game->winningChipPos[counter] = current;
      x++;
    }
    else break;
  }
  if (x >= WINNING_NR) return true;

  //check diagonal right down
  x = 1;
  counter = 0;
  current = lastCoin;
  for(int i = 0; i < WINNING_NR; i++) {
    current = getDiagonalRightDown(current);
    if (current == -1) break;
    if (game->field[current] == p){ 
      counter++;
      game->winningChipPos[counter] = current;
      x++;
    }
    else break;
  }
  //check diagonal left up
  current = lastCoin;
  for(int i = 0; i < WINNING_NR; i++) {
    current = getDiagonalLeftUp(current);
    if (current == -1) break;
    if (game->field[current] == p){ 
      counter++;
      game->winningChipPos[counter] = current;
      x++;
    }
    else break;
  }
  if (x >= WINNING_NR) return true;
  
  //check diagonal left down
  x = 1;
  counter = 0;
  current = lastCoin;
  for(int i = 0; i < WINNING_NR; i++) {
    current = getDiagonalLeftDown(current);
    if (current == -1) break;
    if (game->field[current] == p){ 
      counter++;
      game->winningChipPos[counter] = current;
      x++;
    }
    else break;
  }
  //check diagonal right up
  current = lastCoin;
  for(int i = 0; i < WINNING_NR; i++) {
    current = getDiagonalRightUp(current);
    if (current == -1) break;
    if (game->field[current] == p){ 
      counter++;
      game->winningChipPos[counter] = current;
      x++;
    }
    else break;
  }
  if (x >= WINNING_NR) return true;
  return false;
}
