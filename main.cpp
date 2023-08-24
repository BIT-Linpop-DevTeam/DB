#include "mainwindow.h"
#include "cworkerthread.h"

#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CWOrkerThreadSelect thread1;
    CWOrkerThreadUpdate thread2;

    thread1.start();
    thread2.start();

    thread1.wait();
    thread2.wait();

    qDebug()<<"threads completed";

    MainWindow w;
    w.show();
    return a.exec();
}
