#ifndef CUSER_H
#define CUSER_H

#include<QString>
class CUser{
public:

    explicit CUser(int id_, QString user_name_,QString pass_word_,QString email_,
                   bool is_online_,int last_signout_):
        id_(id_),user_name_(user_name_),pass_word_(pass_word_),email_(email_),
        is_online_(is_online_),last_signout_(last_signout_){}
    ~CUser();

    int id() const;
    void setId(int id);

    QString user_name() const;
    void setUser_name(const QString &user_name);

    QString email() const;
    void setEmail(const QString &email);

    bool is_online() const;
    void setIs_online(bool is_online);

    int last_signout() const;
    void setLast_signout(int last_signout);

private:
    int id_;
    QString user_name_;
    QString pass_word_;
    QString email_;
    bool is_online_;
    int last_signout_;
};

#endif // CUSER_H

