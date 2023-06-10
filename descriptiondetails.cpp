#include "descriptiondetails.h"
#include "description.h"
#include "ui_descriptiondetails.h"

DescriptionDetails::DescriptionDetails(QWidget *parent, Description res) :
    QDialog(parent),
    ui(new Ui::DescriptionDetails)
{
    ui->setupUi(this);

    ui->descriptionText->setPlainText(res.descr);
}

QList<QString> DescriptionDetails::changeRawData()
{
    QList<QString> newList(8, "NO data");
    newList[3] = ui->descriptionText->toPlainText();
    return newList;
}

DescriptionDetails::~DescriptionDetails()
{
    delete ui;
}
