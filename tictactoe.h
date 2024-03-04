#ifndef tictactoe_h
#define tictactoe_h

#include <stdio.h>
#include <stdint.h>

extern char activeplayer;
extern char positions[3][3];
extern int posno;

void computerconfirm(char *compconfirm, uint8_t *isComp);

void enterpos();

int _checkrows(char activeplayer, int posno);
int _checkcolumns(char activeplayer, int posno);
int _checkdiagonals(char activeplayer, int posno);
int checkall(char activeplayer, int posno);

int mainloop();

#endif