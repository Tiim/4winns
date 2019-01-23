#ifndef _INPUT_H_
#define _INPUT_H_

#define BUTTON1 A3
#define BUTTON2 A4
#define BUTTON3 A5

#define B_LEFT BUTTON1
#define B_RIGHT BUTTON2
#define B_ENTER BUTTON3

#define LEFT_PRESSED -1
#define NOTHING_PRESSED 0
#define RIGHT_PRESSED 1
#define ENTER_PRESSED 2

signed char getMove();

#endif
