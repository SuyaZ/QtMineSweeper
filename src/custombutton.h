#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include "head.h"
#include <QMouseEvent>

class CustomButton : public QPushButton
{
public:
    CustomButton(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    int condition = 0;
    //表示方块的状态 0.未排查未标记 1.已排查 2.已标记
};

#endif // CUSTOMBUTTON_H
