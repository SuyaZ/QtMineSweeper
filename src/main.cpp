#include "gamewindow.h"
#include <QApplication>
#include "head.h"

char **mine;
char **showl;

int ROW = 9;
int COL = 9;
//棋盘实际的行和列
int ROWS = ROW + 2;
int COLS = COL + 2;
//用于存放棋盘信息的数组的行和列
//因为扫雷时要对周围八格进行检索，为了使边缘处的方块行为与内部的一致，在数组棋盘的外围加一圈空白
int EASY_COUNT = 10;//雷的数量
int NOT_MINE = ROW * COL - EASY_COUNT;//不含雷的方块数量

int not_mine = 0;// 已排查的无雷方块数量

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned int)time(NULL));
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    //棋盘的初始化
    SetMine(mine, ROW, COL);//雷的布置
    GameWindow *w=new GameWindow;
    w->show();

    return a.exec();
}
