#include "cuser.h"

int CUser::id() const
{
return id_;
}

void CUser::setId(int id)
{
id_ = id;
}

QString CUser::user_name() const
{
return user_name_;
}

void CUser::setUser_name(const QString &user_name)
{
user_name_ = user_name;
}

QString CUser::email() const
{
return email_;
}

void CUser::setEmail(const QString &email)
{
email_ = email;
}

bool CUser::is_online() const
{
return is_online_;
}

void CUser::setIs_online(bool is_online)
{
is_online_ = is_online;
}

int CUser::last_signin() const
{
return last_signin_;
}

void CUser::setLast_signin(int last_signin)
{
last_signin_ = last_signin;
}

int CUser::last_signout() const
{
return last_signout_;
}

void CUser::setLast_signout(int last_signout)
{
last_signout_ = last_signout;
}
