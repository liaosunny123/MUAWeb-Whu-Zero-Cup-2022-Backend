//
// Created by epicmo on 22-10-16.
//

#ifndef MAIN_CC_AUTH_H
#define MAIN_CC_AUTH_H
#pragma once
#include <drogon/HttpController.h>
#include "jsonmodels/AuthModels.h"
using namespace drogon;
using namespace MUAWeb;
class Auth : public drogon::HttpController<Auth>
{
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(Auth::Login, "/login", Post);
        METHOD_ADD(Auth::Register, "/register", Post);
        METHOD_ADD(Auth::EditPassword, "/editPassword", Post);
        METHOD_ADD(Auth::EditUserPassword, "/editUserPassword", Post);
        METHOD_ADD(Auth::RemoveUser, "/removeUser", Post);
        METHOD_ADD(Auth::DisposeToken, "/disposeToken", Post);
        METHOD_ADD(Auth::DisposeToken, "/refreshToken", Post);
    METHOD_LIST_END
    void Login(JsonModels::Auth::Login &&pLogin , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void Register(JsonModels::Auth::Register &&pRegister , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void EditPassword(JsonModels::Auth::EditPassword &&pEditPassword , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void EditUserPassword(JsonModels::Auth::EditUserPassword &&pEditUserPassword , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void RemoveUser(JsonModels::Auth::RemoveUser &&pRemoveUser , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void DisposeToken(JsonModels::Auth::DisposeToken &&pDisposeToken , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void RefreshToken(JsonModels::Auth::RefreshToken &&pRefreshToken , std::function<void (const HttpResponsePtr &)> &&callback) const;
};
#endif //MAIN_CC_AUTH_H
