#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include "proxymodel.h"
#include "aboutpage.h"
#include "descriptiondetails.h"
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_about();

private slots:
    void on_addRow_clicked();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_deletRow_clicked();

    void on_searchButton_clicked();

    void on_resetButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    TableModel *model;
    ProxyModel *proxyModel;

    QMenu *helpMenu;
    QAction *aboutAct;

    void createMenus();
    void createActions();
};
#endif // MAINWINDOW_H
