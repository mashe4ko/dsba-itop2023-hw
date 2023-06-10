#include "logotype.h"
#include <QPainterPath>

logotype::logotype(QWidget *parent)
    : QWidget{parent}
{

}
void logotype::paintEvent(QPaintEvent*)
{

    QPainter painter (this);
    painter.setPen(QColor(175, 97, 60));
    painter.setBrush(QColor(175, 97, 60));
    QRectF rectangle1(0, 0, this->width() - 1, this->height() - 20);
    painter.drawRoundedRect(rectangle1, 20.0, 15.0);
    painter.setPen(QColor(134, 64, 14));
    painter.setBrush(QColor(134, 64, 14));
    QRectF rectangle2(0, 0, this->width() - 130, this->height() - 20);
    painter.drawRoundedRect(rectangle2, 20.0, 5.0);
    painter.setPen(QColor(250, 250, 250));
    painter.setBrush(QColor(255, 255, 255));
    QRectF rectangle3(50.0, 30.0, 90.0, 45.0);
    painter.drawRoundedRect(rectangle3, 20.0, 15.0);
    painter.setPen(QColor(255, 250, 205));
    painter.setBrush(QColor(255, 250, 205));
    QRectF rectangle4(0, 200, this->width() - 1, this->height() - 217);
    painter.drawRoundedRect(rectangle4, 20.0, 10.0);
    painter.setPen(QColor(225, 220, 175));
    painter.setBrush(QColor(225, 220, 175));
    QRectF rectangle5(3, 207, this->width() - 6, this->height() - 248);
    painter.drawRoundedRect(rectangle5, 20.0, 5.0);
    painter.setPen(QColor(225, 220, 175));
    painter.setBrush(QColor(225, 220, 175));
    QRectF rectangle6(3, 216, this->width() - 6, this->height() - 248);
    painter.drawRoundedRect(rectangle6, 20.0, 5.0);
    painter.setPen(QColor(225, 220, 175));
    painter.setBrush(QColor(225, 220, 175));
    QRectF rectangle7(3, 225, this->width() - 6, this->height() - 248);
    painter.drawRoundedRect(rectangle7, 20.0, 5.0);

}
