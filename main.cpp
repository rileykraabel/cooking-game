#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.showPop();
    return a.exec();
}
