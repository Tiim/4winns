#ifndef _INPUT_H_
#define _INPUT_H_

//define button connections
#define BUTTON1 A3
#define BUTTON2 A4
#define BUTTON3 A5

//define which button does what
#define B_LEFT BUTTON1
#define B_RIGHT BUTTON2
#define B_ENTER BUTTON3

#define LEFT_PRESSED -1
#define NOTHING_PRESSED 0
#define RIGHT_PRESSED 1
#define ENTER_PRESSED 2

//returns -1 if move left
//         0 if no move
//         1 if move to the right
//         2 if enter
signed char getMove();

#endif
