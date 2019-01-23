// scrolltext demo for Adafruit RGBmatrixPanel library.
// Demonstrates double-buffered animation on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <RGBmatrixPanel.h>
#include "logic.h"
#include "output.h"
#include "input.h"

#define CLK  8
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

// Last parameter = 'true' enables double-buffering, for flicker-free,
// buttery smooth animation.  Note that NOTHING WILL SHOW ON THE DISPLAY
// until the first call to swapBuffers().  This is normal.
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);
// Double-buffered mode consumes nearly all the RAM available on the
// Arduino Uno -- only a handful of free bytes remain.  Even the
// following string needs to go in PROGMEM:



struct match4 {
    struct gamefield mainfield;
    bool isPlayer1;
    char col;
    chip winner;
    long winTime;
};

struct match4 game;

void setup() { 

  game.col = 3;
  
  matrix.begin();
  pinMode(BUTTON1, INPUT);
  digitalWrite(BUTTON1, HIGH);
  pinMode(BUTTON2, INPUT);
  digitalWrite(BUTTON2, HIGH);
  pinMode(BUTTON3, INPUT);
  digitalWrite(BUTTON3, HIGH);
}

void loop() {
  // Clear background
  matrix.fillScreen(0);

  if (game.winner == empty) {
    signed char move = getMove();
    if (move == ENTER_PRESSED) {
      char field = insertChip(game.isPlayer1? player1: player2, &game.mainfield, game.col);
      if(field != -1) {
        bool isWin = checkWin(&game.mainfield, field);
        if (isWin) {
          game.winner = game.isPlayer1? player1: player2;
          game.winTime = millis();
        }
        game.isPlayer1 = !game.isPlayer1;
      }
    } else {
      game.col = game.col + move;
      if (game.col >= COLS) game.col = COLS-1;
      if (game.col < 0) game.col = 0;
    }
  }

  if(game.winner != empty && game.winTime + 5000 < millis()) {
    // reset game after win in 5 seconds
    memset(game.mainfield.field, 0, sizeof(game.mainfield.field));
    game.winner = empty;
    game.winTime = 0;
    game.col = 6;
  }

  render(&game, &matrix);

#if !defined(__AVR__)
  // On non-AVR boards, delay slightly so screen updates aren't too quick.
  delay(20);
#endif

  // Update display
  matrix.swapBuffers(false);
}
