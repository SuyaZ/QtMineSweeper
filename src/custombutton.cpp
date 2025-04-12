#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent): QPushButton(parent)
{
    setStyleSheet("QPushButton{"
                  "background-color: #8FE1F3;"
                  "border-style: solid;"
                  "border-width: 2px;"
                  "border-color: #71B2D2;"
                  "}");
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        // 如果是右键点击，则修改按钮的样式
        if (condition == 1) return;
        if (condition == 0)
        {
            setStyleSheet("QPushButton{"
                          "background-color: #8FE1F3;"
                          "border-style: solid;"
                          "border-width: 2px;"
                          "border-color: #71B2D2;"
                          "border-image: url(:/icons/icons/note.png);"
                          "}");
             condition = 2;
        }
        else
        {
            setStyleSheet("QPushButton{"
                          "background-color: #8FE1F3;"
                          "border-style: solid;"
                          "border-width: 2px;"
                          "border-color: #71B2D2;"
                          "}");
            condition = 0;
        }
    }
    else
    {
        // 如果是其它的鼠标按键事件，则调用父类的鼠标按下事件处理方法
        QPushButton::mousePressEvent(event);
    }
}
