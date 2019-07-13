#include "about.h"
#include "ui_about.h"
#include <QPixmap>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    QString window_title("About");
    ui->setupUi(this);
    this->setWindowTitle(window_title);
    QPixmap pix("E:/qt_projects/VideoPlayer_New/icons/raindrop_icon.png");
    ui->label_pic->setPixmap(pix.scaled(256,256,Qt::KeepAspectRatio));
}

about::~about()
{
    delete ui;
}

void about::on_developers_button_clicked()
{
    dev = new Developers();
    dev->show();
}

void about::on_License_button_clicked()
{
    license = new License();
    license->show();
}
