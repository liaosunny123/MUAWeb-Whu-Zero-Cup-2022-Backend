//
// Created by epicmo on 22-10-16.
//
#include "Auth.h"
#include "User.h"
#include "UserController.h"
#include "TokenDictionary.h"
#include "JsonError.h"
#include "TokenListener.h"
#include "lib/include/bcrypt.h"
void Auth::Login(JsonModels::Auth::Login &&pLogin,
                 std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (bcrypt::validatePassword(UserController::getPassword(pLogin.username),pLogin.password)){
        LOG_INFO << "User try to login with error password. Username:" << pLogin.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"不正确的账号或密码"));
        return;
    } else{
        Json::Value json;
        json["status"] = true;
        Token *token = new Token(pLogin.username);
        json["token"] = token->token;
        auto resp=HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}

void Auth::Register(JsonModels::Auth::Register &&pRegister,
                    std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pRegister.username)){
        LOG_WARN << "User try to register without Token. Username:" << pRegister.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (!UserController::getUserFromDictionary(pRegister.username).isRoot()){
        LOG_INFO << "User try to register without Root Permission. Username:" << pRegister.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pRegister.username).token != pRegister.token){
        LOG_WARN << "User try to register without RightToken" << pRegister.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (UserController::isExist(pRegister.reg_username)){
        LOG_INFO << "User create existed user:" << pRegister.reg_username;
        callback(MUAWeb::JsonError::ErrorResponse(404,"不能创建已经存在的用户。"));
        return;
    }

    User *user = new User(pRegister.reg_username,pRegister.reg_password);
    UserController::createUser(*user);
    delete user;
    Json::Value json;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k204NoContent);
    callback(resp);
}

void Auth::EditPassword(JsonModels::Auth::EditPassword &&pEditPassword,
                 std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pEditPassword.username)){
        LOG_WARN << "User try to editPassword without Token. Username:" << pEditPassword.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pEditPassword.username).token != pEditPassword.token){
        LOG_WARN << "User try to editPassword without RightToken" << pEditPassword.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }
    User *user = new User(pEditPassword.username);
    UserController::editPassword(*user,pEditPassword.newpassword);
    Json::Value json;
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k200OK);
    delete user;
    callback(resp);
}


void Auth::EditUserPassword(JsonModels::Auth::EditUserPassword &&pEditUserPassword,
                 std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pEditUserPassword.username)){
        LOG_WARN << "User try to editUserPassword without Token. Username:" << pEditUserPassword.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (!UserController::getUserFromDictionary(pEditUserPassword.username).isRoot()){
        LOG_WARN << "User try to editUserPassword without Root Permission. Username:" << pEditUserPassword.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pEditUserPassword.username).token != pEditUserPassword.token){
        LOG_WARN << "User try to editUserPassword without RightToken" << pEditUserPassword.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (!UserController::isExist(pEditUserPassword.targetuser)){
        LOG_INFO << "User edit unexisted user:" << pEditUserPassword.targetuser;
        callback(MUAWeb::JsonError::ErrorResponse(404,"不能修改不存在的用户的密码。"));
        return;
    }

    User *user = new User(pEditUserPassword.targetuser);
    UserController::editPassword(*user,pEditUserPassword.targetpassword);
    delete user;
    Json::Value json;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k204NoContent);
    callback(resp);
}

void Auth::RemoveUser(JsonModels::Auth::RemoveUser &&pRemoveUser,
                            std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pRemoveUser.username)){
        LOG_WARN << "User try to remove user  without Token. Username:" << pRemoveUser.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (!UserController::getUserFromDictionary(pRemoveUser.username).isRoot()){
        LOG_WARN << "User try to remove user without Root Permission. Username:" << pRemoveUser.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pRemoveUser.username).token != pRemoveUser.token){
        LOG_WARN << "User try to remove user without RightToken" << pRemoveUser.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (!UserController::isExist(pRemoveUser.targetusername)){
        LOG_INFO << "User remove unexisted user:" << pRemoveUser.targetusername;
        callback(MUAWeb::JsonError::ErrorResponse(404,"不能删除不存在的用户。"));
        return;
    }

    User *user = new User(pRemoveUser.targetusername);
    UserController::deleteUser(*user);
    delete user;
    Json::Value json;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k204NoContent);
    callback(resp);
}

void Auth::DisposeToken(JsonModels::Auth::DisposeToken &&pDisposeToken,
                 std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (TokenDictionary::getToken(pDisposeToken.username).token != pDisposeToken.token){
        LOG_WARN << "User try to disposeToken without RightToken" << pDisposeToken.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    TokenDictionary::removeTokenAt(pDisposeToken.username);
    Json::Value json;
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}


void Auth::RefreshToken(JsonModels::Auth::RefreshToken &&pRefreshToken,
                        std::function<void (const HttpResponsePtr &)> &&callback) const{

    if (TokenDictionary::getToken(pRefreshToken.username).token != pRefreshToken.token){
        LOG_WARN << "User try to register without RightToken" << pRefreshToken.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"密钥失效！"));
        return;
    }
    TokenListener::freshToken(pRefreshToken.username);
    Json::Value json;
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}