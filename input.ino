#include "input.h"

#define FLAG_LEFT 1
#define FLAG_RIGHT 2
#define FLAG_ENTER 4

signed char getMove() {
  static char debounceFlag = 0;
  bool wasPressed = false;
  bool x = digitalRead(B_LEFT) == LOW;
  if (x && !(debounceFlag & FLAG_LEFT)) {
    debounceFlag |= FLAG_LEFT;
    return LEFT_PRESSED;
  }
  wasPressed = wasPressed || x;
  x = digitalRead(B_RIGHT) == LOW;
  if (x && !(debounceFlag & FLAG_RIGHT)) {
    debounceFlag |= FLAG_RIGHT;
    return RIGHT_PRESSED;
  }
  wasPressed = wasPressed || x;
  x = digitalRead(B_ENTER) == LOW;
  if (x && !(debounceFlag & FLAG_ENTER)) {
    debounceFlag |= FLAG_ENTER;
    return ENTER_PRESSED;
  }
  wasPressed = wasPressed || x;
  if(!wasPressed) {
    debounceFlag = 0;
  }
  return NOTHING_PRESSED;
}
