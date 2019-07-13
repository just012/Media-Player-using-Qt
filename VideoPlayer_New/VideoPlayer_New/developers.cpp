#include "developers.h"
#include "ui_developers.h"
#include <QPixmap>

Developers::Developers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Developers)
{
    QString window_title("Our Team");
    ui->setupUi(this);
    this->setWindowTitle(window_title);
    QPixmap pix1("E:/qt_projects/VideoPlayer_New/icons/lakshya.jpeg");
    ui->label_pic_1->setPixmap(pix1.scaled(150,160,Qt::KeepAspectRatio));

    QPixmap pix2("E:/qt_projects/VideoPlayer_New/icons/new_just.jpg");
    ui->label_pic_2->setPixmap(pix2.scaled(160,160,Qt::KeepAspectRatio));

    QPixmap pix3("E:/qt_projects/VideoPlayer_New/icons/new_prince.jpg");
    ui->label_pic_3->setPixmap(pix3.scaled(150,160,Qt::KeepAspectRatio));

    QPixmap pix4("E:/qt_projects/VideoPlayer_New/icons/dipesh.jpeg");
    ui->label_pic_4->setPixmap(pix4.scaled(150,160,Qt::KeepAspectRatio));
}

Developers::~Developers()
{
    delete ui;
}
