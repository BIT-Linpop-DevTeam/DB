#ifndef CWORKERTHREAD_H
#define CWORKERTHREAD_H

#include "dbhelper.h"
#include <QCoreApplication>
#include <QtSql>
#include <QThread>
#include <QDebug>
#include <QString>

class CWorkerThreadInsert : public QThread {
    Q_OBJECT
public:
    void run() override {

        auto temp_dbhelper = CDBHelper::GetInstance();
        for (int i = 0; i < 3; ++i) {
            temp_dbhelper->changeData(tr("insert into users (username) values ('%1')")
                                 .arg(QString("Value %1").arg(QString::number(i))));
        }

        qDebug() << "insert completed.";
    }
};

class CWorkerThreadDelete :public QThread{
    Q_OBJECT
public:
    void run() override{

        auto temp_dbhelper = CDBHelper::GetInstance();
        for(int i=100;i<=200;++i){
            temp_dbhelper->changeData(tr("delete from users where id=%1").arg(QString::number(i+10)));
        }
        qDebug() << "delete completed";
    }
};

class CWOrkerThreadUpdate:public QThread{
    Q_OBJECT
public:
    void run() override{
        auto temp_dbhelper = CDBHelper::GetInstance();

        for(int i=200;i<=300;++i){
            temp_dbhelper->changeData(tr("update users set username = '%1' where id=%2")
                                      .arg(QString::number(i+10))
                                      .arg(QString::number(i))
                                      );
        }
    }
};

class CWOrkerThreadSelect:public QThread{
    Q_OBJECT
public:
    void run() override{
        auto temp_dbhelper = CDBHelper::GetInstance();

        for(int i=201;i<=206;++i){
            QString username;
            temp_dbhelper->selectData(tr("select username from users where id=%1")
                                      .arg(QString::number(i))
                                      ,username);
            qDebug()<<username;
        }
    }
};


#endif // CWORKERTHREAD_H
