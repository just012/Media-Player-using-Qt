#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QPushButton>
#include "about.h"
#include "playlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString filename;
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionmute_triggered();

    void on_actionFF_triggered();

    void on_actionrewind_triggered();

    void on_actionfull_screen_triggered();

    //void seek(int seconds);

    void on_actionAbout_triggered();

    void on_actionPower_triggered();
    void on_actionplayList_triggered();

    //void showColorDialog();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QSlider* slider;
    QSlider* volume;
    QLabel *m_labelDuration = nullptr;
    about *a;
    playlist *PlayList;
    //QPushButton *colorButton;
    //QDialog *colorDialog;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // MAINWINDOW_H
