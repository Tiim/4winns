#ifndef _LOGIC_H_
#define _LOGIC_H_

#define COLS 7
#define ROWS 6
#define FIELDS (COLS * ROWS)
#define WINNING_NR 4

enum chip : unsigned char {
  empty,
  player1,
  player2
};

struct gamefield {
    chip field[FIELDS];
};

// calculates what happens if [player] inserts a coin in [collumn]
// handles all neccesairy mutations to the [game] struct
// returns chip position or -1 if no chip was inserted
int insertChip(chip* player, struct gamefield* game, int collumn);
// checks if the last move was a win. Only checks for the coin position [lastCoin]
bool checkWin(struct gamefield* game, int lastCoin);
// returns the row of a given field
inline int getRow(int field);
// returns the collumn of a given field
inline int getCol(int field);

#endif
