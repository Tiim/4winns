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

int insertChip(chip* player, struct gamefield* game, int collumn);
bool checkWin(struct gamefield* game, int lastCoin);
inline int getRow(int field);
inline int getCol(int field);

#endif
