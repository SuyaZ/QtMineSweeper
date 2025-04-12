#include "gamewindow.h"
#include "ui_GameWindow.h"
#include <QSignalMapper>


GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    createBoard();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->spinBox->hide();
    ui->spinBox_2->hide();
    ui->spinBox_3->hide();
    ui->pushButton_7->hide();
}

void GameWindow::createBoard()
{
    for (int i=0;i<ROW;i++)
        for (int j=0;j<COL;j++)
        {
            CustomButton *button=new CustomButton(this);
            button->setGeometry(365-(double(COL)/2)*30+j*30,180+i*30,30,30);
            //为了控制棋盘生成的位置在窗口的中央，我联系窗口和棋盘的尺寸进行了计算
            button->show();
            buttons.append(button);
            QSignalMapper *mapper=new QSignalMapper(this);
            mapper->setMapping(button,i*COL+j);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
            connect(mapper, SIGNAL(mapped(int)), this, SLOT(onButtonClicked(int)));
        }
}

void GameWindow::deleteBoard(int row_old, int col_old)
{
    for (int i=0;i<row_old*col_old;i++)
    {
        delete buttons[i];
    }
    QVector<CustomButton *> tmp;
    buttons.swap(tmp);
}

void GameWindow::onButtonClicked(int index)
{
    if (buttons[index]->condition == 1 || buttons[index]->condition == 2)return;
    int x=0,y=0;
    x=index/COL;
    y=index-x*COL+1;
    x++;
    if (mine[x][y] == '1')
    {
        not_mine=0;
        this->ui->label_result->setText("对不起，你踩雷了。");
        this->ui->label_face->setStyleSheet("QLabel{"
                                            "border-image: url(:/icons/icons/sad.png);"
                                            "}");
        reveal_All(mine, showl, this, ROW, COL);
        return;
    }
    else
    {
        Sweep(mine, showl, this, ROW, COL, x, y);
        if (not_mine == NOT_MINE)
        {
            not_mine=0;
            this->ui->label_result->setText("恭喜你，扫雷成功！");
            this->ui->label_face->setStyleSheet("QLabel{"
                                                "border-image: url(:/icons/icons/cool.png);"
                                                "}");
            return;
        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}


void GameWindow::on_pushButton_restart_clicked()
{
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    SetMine(mine, ROW, COL);
    not_mine = 0;
    ui->label_result->setText("");
    ui->label_face->setStyleSheet("border-image: url(:/icons/icons/smile.png);");
    deleteBoard(ROW, COL);
    createBoard();
}

void GameWindow::on_pushButton_quit_clicked()
{
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] mine[i];
        delete[] showl[i];
    }
    delete[] mine;
    delete[] showl;
    deleteBoard(ROW, COL);
    QApplication::quit();
}

void GameWindow::on_pushButton_2_clicked()
{
    deleteBoard(ROW, COL);
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] mine[i];
        delete[] showl[i];
    }
    delete[] mine;
    delete[] showl;
    ROW = 11;
    COL = 11;
    ROWS = 13;
    COLS = 13;
    EASY_COUNT = 15;
    NOT_MINE = ROW * COL - EASY_COUNT;
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    SetMine(mine, ROW, COL);
    not_mine = 0;
    ui->label_result->setText("");
    ui->label_face->setStyleSheet("border-image: url(:/icons/icons/smile.png);");
    createBoard();
}

void GameWindow::on_pushButton_clicked()
{
    deleteBoard(ROW, COL);
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] mine[i];
        delete[] showl[i];
    }
    delete[] mine;
    delete[] showl;
    ROW = 9;
    COL = 9;
    ROWS = 11;
    COLS = 11;
    EASY_COUNT = 10;
    NOT_MINE = ROW * COL - EASY_COUNT;
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    SetMine(mine, ROW, COL);
    not_mine = 0;
    ui->label_result->setText("");
    ui->label_face->setStyleSheet("border-image: url(:/icons/icons/smile.png);");
    createBoard();
}

void GameWindow::on_pushButton_6_clicked()
{
    deleteBoard(ROW, COL);
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] mine[i];
        delete[] showl[i];
    }
    delete[] mine;
    delete[] showl;
    ROW = 4;
    COL = 4;
    ROWS = 6;
    COLS = 6;
    EASY_COUNT = 5;
    NOT_MINE = ROW * COL - EASY_COUNT;
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    SetMine(mine, ROW, COL);
    not_mine = 0;
    ui->label_result->setText("");
    ui->label_face->setStyleSheet("border-image: url(:/icons/icons/smile.png);");
    createBoard();
}

void GameWindow::on_pushButton_3_clicked()
{
    deleteBoard(ROW, COL);
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] mine[i];
        delete[] showl[i];
    }
    delete[] mine;
    delete[] showl;
    ROW = 11;
    COL = 16;
    ROWS = 13;
    COLS = 18;
    EASY_COUNT = 25;
    NOT_MINE = ROW * COL - EASY_COUNT;
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    SetMine(mine, ROW, COL);
    not_mine = 0;
    ui->label_result->setText("");
    ui->label_face->setStyleSheet("border-image: url(:/icons/icons/smile.png);");
    createBoard();
}

void GameWindow::on_pushButton_4_clicked()
{
    deleteBoard(ROW, COL);
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] mine[i];
        delete[] showl[i];
    }
    delete[] mine;
    delete[] showl;
    ROW = 11;
    COL = 22;
    ROWS = 13;
    COLS = 24;
    EASY_COUNT = 30;
    NOT_MINE = ROW * COL - EASY_COUNT;
    NOT_MINE = ROW * COL - EASY_COUNT;
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    SetMine(mine, ROW, COL);
    not_mine = 0;
    ui->label_result->setText("");
    ui->label_face->setStyleSheet("border-image: url(:/icons/icons/smile.png);");
    createBoard();
}

void GameWindow::on_pushButton_5_clicked()
{
    if (is_custom)
    {
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->spinBox->hide();
        ui->spinBox_2->hide();
        ui->spinBox_3->hide();
        ui->pushButton_7->hide();
        is_custom = false;
        return;
    }
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->spinBox->show();
    ui->spinBox_2->show();
    ui->spinBox_3->show();
    ui->pushButton_7->show();
    is_custom = true;
}

void GameWindow::on_pushButton_7_clicked()
{
    ui->label_5->setText("");
    int Column = ui->spinBox->value();
    int Row = ui->spinBox_2->value();
    int Mine = ui->spinBox_3->value();
    if ( Mine >= Column * Row)
    {
        ui->label_5->setText("雷的数量应该少于格子的数量！");
        return;
    }
    is_custom = false;
    deleteBoard(ROW, COL);
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] mine[i];
        delete[] showl[i];
    }
    delete[] mine;
    delete[] showl;

    COL = Column;
    ROW = Row;
    COLS = COL + 2;
    ROWS = ROW + 2;
    EASY_COUNT = Mine;
    NOT_MINE = ROW * COL - EASY_COUNT;
    not_mine = 0;
    ui->label_result->setText("");
    ui->label_face->setStyleSheet("border-image: url(:/icons/icons/smile.png);");

    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(showl, ROWS, COLS, '*');
    SetMine(mine, ROW, COL);
    createBoard();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->spinBox->hide();
    ui->spinBox_2->hide();
    ui->spinBox_3->hide();
    ui->pushButton_7->hide();
}
