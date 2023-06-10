#ifndef DESCRIPTIONDETAILS_H
#define DESCRIPTIONDETAILS_H

#include "description.h"
#include <QDialog>

namespace Ui {
class DescriptionDetails;
}

class DescriptionDetails : public QDialog
{
    Q_OBJECT

public:
    explicit DescriptionDetails(QWidget *parent = nullptr, Description res = Description());
    QList<QString> changeRawData();
    ~DescriptionDetails();

private:
    Ui::DescriptionDetails *ui;
};

#endif // DESCRIPTIONDETAILS_H
