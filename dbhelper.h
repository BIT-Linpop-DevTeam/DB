#ifndef DBHELPER_H
#define DBHELPER_H

#include "cuser.h"


#include<QString>
#include<QtSql/QSqlDatabase>
#include<QThread>
#include<QMap>
#include<QDebug>
#include<QtSql/QSqlQuery>
#include<QFile>
#include<QStandardItem>
#include<QObject>

class CDBHelper:public QObject
{
    Q_OBJECT
public:
    static CDBHelper* GetInstance();

    explicit CDBHelper() ;

    ~CDBHelper(){}

    QSqlQuery getAllData(QStandardItemModel* model);

    int getSize();



//    /**
//     * @brief getFriends
//     * @param[out] user_friends: Return a vector containing all friend information.
//     * @return false if user_id not exist in db, otherwise true.
//     */
//    bool getFriends(int user_id,std::vector<CUser>&user_friends);

//    /**
//     * @param[out] the pointer of the user.
//     * @return false if user_id not exist, otherwise true.
//     */
//    bool getUser(int user_id, CUser* cur_user);

//    /**
//     * @brief get messages between two users.
//     * @param[out] user_messages: Return a vector containing some of the most recently
//     * 			sent messages from user1 or user2.
//     * @param messages_num: find messages_num most recent messages.
//     * @return false if at least one user does not exist, otherwise true
//     */
//    bool getMessages(int user_one_id, int user_two_id, std::vector<CMessage>&user_messages,
//                         int messages_num = 100);

    bool selectData(QString sql, QString& username);
    bool changeData(QString username);

private:
    static QMap<Qt::HANDLE, CDBHelper*> databaseMap;//所有数据库链接,key: 线程ID， value 数据库链接实例指针
    QSqlDatabase database;//当前线程数据库链接
    void query(QString sql);
};


#endif // DBHELPER_H
