#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
}

QList<QString> AddRowDialog::getRowData()
{
    QList<QString> newList(8, "No data");
    newList[0] = ui->titleLine->text();
    newList[1] = ui->authorLine->text();
    newList[2] = ui->ratingLine->text();
    newList[3] = ui->descriptionLine->text();
    newList[4] = ui->languageLine->text();
    newList[5] = ui->genresLine->text();
    newList[6] = ui->bookformatLine->text();
    newList[7] = ui->pagesLine->text();
    return newList;
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}
