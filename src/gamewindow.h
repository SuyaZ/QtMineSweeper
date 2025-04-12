#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#pragma execution_character_set("utf-8")

#include <QWidget>
#include "head.h"
#include "custombutton.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    QVector<CustomButton *> buttons;
    bool is_custom = false;
    void createBoard();
    void GameWindow::deleteBoard(int row_old, int col_old);

public slots:
    void onButtonClicked(int index);
private slots:
    void on_pushButton_restart_clicked();

    void on_pushButton_quit_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
