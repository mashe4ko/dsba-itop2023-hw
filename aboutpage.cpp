#include "aboutpage.h"
#include "ui_aboutpage.h"

aboutPage::aboutPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutPage)
{
    ui->setupUi(this);

    logotype = new ::logotype(ui->widgetLogo);

    ui->horizontalLayout->addWidget(logotype);


    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(logotype->sizePolicy().hasHeightForWidth());
    logotype->setSizePolicy(sizePolicy);


}

aboutPage::~aboutPage()
{
    delete ui;
}
