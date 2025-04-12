#define _CRT_SECURE_NO_WARNINGS 1

extern int ROW;
extern int COL;
extern int ROWS;
extern int COLS;
extern int EASY_COUNT;
extern int NOT_MINE;

#include <QDebug>
#include <QPushButton>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int not_mine;
extern char **mine;
extern char **showl;

class GameWindow;

void InitBoard(char **&board, int rows, int cols, char set);
void SetMine(char **board, int row, int col);
void Sweep(char **mine, char **showl, GameWindow* w, int row, int col, int x, int y);
void reveal_All(char **mine, char **show, GameWindow* w,int row, int col);
