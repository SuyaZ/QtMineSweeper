#include "head.h"
#include "gamewindow.h"

//棋盘的初始化，set表示用于填充的值
void InitBoard(char**& board, int rows, int cols, char set)
{
    board = new char*[rows];
    for (int i=0;i<rows;i++)
        board[i] = new char[cols];
    for (int i = 0;i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
}

//布置雷
void SetMine(char **board, int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

//递归实现扫雷
void Sweep(char **mine, char **show, GameWindow* w,int row, int col, int x, int y)
{
    int index=y-1+(x-1)*COL;
    if (x <= 0 || x > row || y <= 0 || y > col)
    {
        return;
    }
    if (show[x][y]!='*')return;
    int count = mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - '0' * 8;
    show[x][y]=count+'0';
    w->buttons[index]->setText(QString::number(count));
    w->buttons[index]->setStyleSheet("QPushButton{"
                                     "font-size: 20px;"
                                     "background-color: #89CDEF;"
                                     "border-style: solid;"
                                     "border-width: 1px;"
                                     "border-color: #71B2D2;"
                                     "}");
    w->buttons[index]->condition = 1;
    not_mine++;
    qDebug()<< not_mine;

    if (count == 0)
    {
        Sweep(mine, show, w, row, col, x - 1, y - 1);
        Sweep(mine, show, w, row, col, x - 1, y);
        Sweep(mine, show, w, row, col, x - 1, y + 1);
        Sweep(mine, show, w, row, col, x, y - 1);
        Sweep(mine, show, w, row, col, x, y + 1);
        Sweep(mine, show, w, row, col, x + 1, y - 1);
        Sweep(mine, show, w, row, col, x + 1, y);
        Sweep(mine, show, w, row, col, x + 1, y + 1);
    }
}

//踩雷时，棋盘应显示全部信息
void reveal_All(char **mine, char **show, GameWindow* w,int row, int col)
{
    for (int i=1;i<=row;i++)
        for (int j=1;j<=col;j++)
        {
            int index=j-1+(i-1)*COL;
            if (mine[i][j]=='1')
            {
                w->buttons[index]->condition = 1;
                w->buttons[index]->setStyleSheet("QPushButton{"
                                                 "background-color: #89CDEF;"
                                                 "border-image: url(:/icons/icons/mine.png);"
                                                 "border-style: solid;"
                                                 "border-width: 1px;"
                                                 "border-color: #71B2D2;"
                                                 "}");
            }
            else Sweep(mine, show, w, row, col, i, j);
        }
}
