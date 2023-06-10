#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>
#include "logotype.h"

namespace Ui {
class aboutPage;
}

class aboutPage : public QWidget
{
    Q_OBJECT

public:
    explicit aboutPage(QWidget *parent = nullptr);
    ~aboutPage();

private:
    Ui::aboutPage *ui;
    logotype* logotype;
};

#endif // ABOUTPAGE_H
