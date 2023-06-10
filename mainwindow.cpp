#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"
#include "description.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new TableModel), proxyModel(new ProxyModel)
{
    ui->setupUi(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(1, Qt::AscendingOrder);
   for (int i = 0; i < 8; i++)
   {
       if (i != 0)
           ui->tableView->setColumnHidden(i, true);
   }

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::on_about);
}

void MainWindow::on_about()
{
    aboutPage* page = new aboutPage;
    page->show();
}

void MainWindow::createMenus()
{
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QList<QString> targetLine =(*model)[proxyModel->mapToSource(index).row()];
    ui->titleLine->setText(targetLine[0]);
    ui->authorLine->setText(targetLine[1]);
    ui->ratingLine->setText(targetLine[2]);
    ui->descriptionLine->setText(targetLine[3]);
    ui->languageLine->setText(targetLine[4]);
    ui->genresLine->setText(targetLine[5]);
    ui->bookformatLine->setText(targetLine[6]);
    ui->pagesLine->setText(targetLine[7]);
}


void MainWindow::on_addRow_clicked()
{
//    model->addRow(QList<QString>());
    AddRowDialog dialog;
    if (dialog.exec())
    {
        model->addRow(dialog.getRowData());
    }
//    if (dialog.close()){}
}


void MainWindow::on_deletRow_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    qDebug()<<select->selectedIndexes();
    if (select->hasSelection())
        model->deleteRow(proxyModel->mapToSource(select->selectedIndexes()[0]).row());
}

void MainWindow::on_searchButton_clicked()
{
    QString needToSearch = ui->searchLine->text();
    proxyModel->setTitle(needToSearch);
}

void MainWindow::on_resetButton_clicked()
{
    proxyModel->setTitle("");
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    ui->searchLine->setText("");
}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QList<QString> targetLine =(*model)[proxyModel->mapToSource(index).row()];
    Description res = {targetLine[3]};
    QItemSelectionModel *select = ui->tableView->selectionModel();

    DescriptionDetails details(0, res);
    model->deleteRow(proxyModel->mapToSource(select->selectedIndexes()[0]).row());
    if (details.exec())
        model->addRow(details.changeRawData());
}
