#include "dbhelper.h"

#include<QString>
#include<QtSql/QSqlDatabase>
#include<QThread>
#include<QMap>
#include<QDebug>
#include<QtSql/QSqlQuery>
#include<QFile>
#include<QStandardItem>
#include<QObject>


CDBHelper::CDBHelper(){
    //创建数据库链接并指定链接名称
    this->database = QSqlDatabase::addDatabase("QSQLITE", QString::number((long long)QThread::currentThreadId()));
    this->database.setDatabaseName("this_db");
    if(!this->database.open()) //是否打开成功判断
    {
        qDebug() << "database open error thread"<<QThread::currentThreadId();
        exit(1);
    }else{
        qDebug() << "database open thread"<< QThread::currentThreadId();
        QSqlQuery query(this->database);
        query.exec("select * from sqlite_master where type = 'table' and name = 'users'");
        if(query.next() == false){
            query.exec("drop table users");
            query.exec("create table users("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "username varchar,"
                       "password varchar,"
                       "email varchar,"
                       "last_signout varchar"
                       ")");
        }
    }
    this->database.close();
}

void CDBHelper::query(QString sql){
    this->database.open();
    QSqlQuery sql_query(this->database);//必须指定当前数据库实例
    qDebug() << sql_query.exec(sql);//是否执行成功判断
    this->database.close();
}

CDBHelper* CDBHelper::GetInstance() {
    if(!databaseMap.contains(QThread::currentThreadId())) {
        databaseMap.insert(QThread::currentThreadId(), new CDBHelper());
    }
    return databaseMap[QThread::currentThreadId()];
}

QSqlQuery CDBHelper::getAllData(QStandardItemModel *model){
    this->database.open();
    QSqlQuery sql_query(this->database);
    qDebug()<<sql_query.exec("select * from users;");
    int row = 0;
    while(sql_query.next()){
        qDebug()<< sql_query.value("id").toString()<<" "<< sql_query.value("password").toString();
        int id = sql_query.value("id").toInt();
        QString username = sql_query.value("username").toString();
        model->setItem(row, 0, new QStandardItem(QString::number(id)));
        model->setItem(row, 1, new QStandardItem(username));
        row++;
    }
    this->database.close();
    return sql_query;
}

int CDBHelper::getSize(){
    this->database.open();
    QSqlQuery sql_query(this->database);
    qDebug()<<sql_query.exec("select count(*) from users;");
    while(sql_query.next()){
        this->database.close();
        return sql_query.value(0).toInt();
    }
    this->database.close();
    qDebug()<<"getSize() error";
    return -1;
}

bool CDBHelper::selectData(QString sql, QString& username){
    this->database.open();
    QSqlQuery query(this->database);
    if(!query.exec(sql)){
        this->database.close();
        return false;
    }
    while(query.next()){
        username = query.value("username").toString();
    }
    this->database.close();
    return true;;
}

bool CDBHelper::changeData(QString sql){
    this->database.open();
    QSqlQuery query(this->database);
    if(!query.exec(sql)){
        this->database.close();
        return false;
    }
    this->database.close();
    return true;
}

bool CDBHelper::login(int user_id, QString &user_name){
    this->database.open();
    QSqlQuery query(this->database);
    query.exec(tr("select * from user where id=%1").arg(QString::number(user_id)));
    while(query.next()){
        user_name = query.value("username").toString();

    }
    this->database.close();
}
