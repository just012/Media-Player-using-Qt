#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QtGui>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget dw;

    a.setWindowIcon(QIcon("E:/qt_projects/VideoPlayer_New/icons/raindrop_icon.png"));

    int x=dw.width()*0.5;
    int y=dw.height()*0.5;
    w.setBaseSize(x,y);

    int width = (dw.width() - x)/2;
    int height = (dw.height() - y)/2;

    w.move(width, height);

    w.show();



    return a.exec();
}
