#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QMouseEvent>
#include <QString>
#include <QKeyEvent>
#include <QStatusBar>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString window_title("Raindrop Media Player");
    ui->setupUi(this);
    this->setWindowTitle(window_title);

    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::white);
    setPalette(p);

    //setAttribute(Qt::WA_OpaquePaintEvent);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    slider = new QSlider(this);
    volume = new QSlider(this);

    slider->setOrientation(Qt::Horizontal);
    slider->setFixedWidth(580);
    slider->setRange(0, player->duration() / 1000);

    volume->setOrientation(Qt::Horizontal);
    volume->setRange(0, 100);
    volume->setFixedWidth(100);
    volume->setValue(100);

    ui->statusBar->addPermanentWidget(slider);
    ui->statusBar->addPermanentWidget(volume);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(volume, SIGNAL(valueChanged(int)),player, SLOT(setVolume(int)));

//    colorButton = new QPushButton(tr("Color Options..."), this);
//    colorButton->setEnabled(true);
//    connect(colorButton, &QPushButton::clicked, this, &MainWindow::showColorDialog);
//    ui->statusBar->addPermanentWidget(colorButton);

}

MainWindow::~MainWindow()
{
    delete ui;
    //qreal rate = 1.0;
}

void MainWindow::on_actionOpen_triggered()
{
    filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    player->setPlaybackRate(1.0);
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
}


void MainWindow::on_actionmute_triggered()
{
    if(ui->actionmute->text() == "Mute")
    {
        player->setMuted(true);
        ui->actionmute->setText("Unmute");
    }
    else
    {
        player->setMuted(false);
        ui->actionmute->setText("Mute");
    }
}

void MainWindow::on_actionFF_triggered()
{
    player->setPlaybackRate(2.0);
}

void MainWindow::on_actionrewind_triggered()
{
    player->setPlaybackRate(0.5);
}

void MainWindow::on_actionfull_screen_triggered()
{
    //isFullScreen() ? showNormal() : showFullScreen();
    if(isFullScreen()){
        showNormal();
        ui->menuBar->show();
    }
    else
    {
        showFullScreen();
        ui->menuBar->hide();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    a = new about();
    a->show();
    on_actionPause_triggered();
}

void MainWindow::on_actionPower_triggered()
{
     qApp->exit();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape && isFullScreen())
    {
        showNormal();
        ui->menuBar->show();
        event->accept();
    }
//    else
//    {
//        QVideoWidget::keyPressEvent(event);
//    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(isFullScreen()){
        showNormal();
        ui->menuBar->show();
    }
    else
    {
        showFullScreen();
        ui->menuBar->hide();
    }
    event->accept();
}

void MainWindow::on_actionplayList_triggered(){
    PlayList = new playlist();
    PlayList->AddtoList(filename);
    PlayList->show();
}
