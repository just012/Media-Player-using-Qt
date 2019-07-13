#include "playlist.h"
#include "ui_playlist.h"

playlist::playlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playlist)
{
    ui->setupUi(this);
    ui->listWidget->addItem("PLAYLIST");
}

playlist::~playlist()
{
    delete ui;
}

void playlist::AddtoList(const QString filename){
    ui->listWidget->addItem(filename);
}
