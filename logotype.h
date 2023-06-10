#ifndef LOGOTYPE_H
#define LOGOTYPE_H

#include <QWidget>
#include <QPainter>

class logotype : public QWidget
{
    Q_OBJECT
public:
    explicit logotype(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

};

#endif // LOGOTYPE_H
