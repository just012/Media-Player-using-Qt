#include "license.h"
#include "ui_license.h"

License::License(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::License)
{
    QString window_title("License");
    ui->setupUi(this);
    this->setWindowTitle(window_title);
}

License::~License()
{
    delete ui;
}
