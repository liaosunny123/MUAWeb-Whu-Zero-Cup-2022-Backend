//
// Created by epicmo on 22-10-16.
//

#ifndef MAIN_CC_AUTHMODELS_H
#define MAIN_CC_AUTHMODELS_H
#include <iostream>
#include <drogon/HttpRequest.h>
namespace MUAWeb::JsonModels::Auth{
    struct Login{
        std::string username;
        std::string password;
    };
    struct Register{
        std::string username;
        std::string token;
        std::string reg_username;
        std::string reg_password;
    };
    struct EditPassword{
        std::string username;
        std::string token;
        std::string newpassword;
    };
    struct EditUserPassword{
        std::string username;
        std::string token;
        std::string targetuser;
        std::string targetpassword;
    };
    struct RemoveUser{
        std::string username;
        std::string token;
        std::string targetusername;
    };
    struct DisposeToken{
        std::string username;
        std::string token;
    };
}
namespace drogon{
    template <>
    inline MUAWeb::JsonModels::Auth::Login fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        MUAWeb::JsonModels::Auth::Login user;
        if (json){
            user.username = (*json)["username"].asString();
            user.password = (*json)["passwd"].asString();
        }
        return user;
    }
    template <>
    inline MUAWeb::JsonModels::Auth::Register fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        MUAWeb::JsonModels::Auth::Register user;
        if (json){
            user.username = (*json)["username"].asString();
            user.token = (*json)["token"].asString();
            user.reg_username = (*json)["reg_username"].asString();
            user.reg_password = (*json)["reg_password"].asString();
        }
        return user;
    }
    template <>
    inline MUAWeb::JsonModels::Auth::EditPassword fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        MUAWeb::JsonModels::Auth::EditPassword user;
        if (json){
            user.username = (*json)["username"].asString();
            user.token = (*json)["token"].asString();
            user.newpassword = (*json)["newpassword"].asString();
        }
        return user;
    }
    template <>
    inline MUAWeb::JsonModels::Auth::EditUserPassword fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        MUAWeb::JsonModels::Auth::EditUserPassword user;
        if (json){
            user.username = (*json)["username"].asString();
            user.token = (*json)["token"].asString();
            user.targetpassword = (*json)["targetpassword"].asString();
            user.targetuser = (*json)["targetuser"].asString();
        }
        return user;
    }
    template <>
    inline MUAWeb::JsonModels::Auth::RemoveUser fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        MUAWeb::JsonModels::Auth::RemoveUser user;
        if (json){
            user.username = (*json)["username"].asString();
            user.token = (*json)["token"].asString();
            user.targetusername = (*json)["targetusername"].asString();
        }
        return user;
    }
    template <>
    inline MUAWeb::JsonModels::Auth::DisposeToken fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        MUAWeb::JsonModels::Auth::DisposeToken user;
        if (json){
            user.username = (*json)["username"].asString();
            user.token = (*json)["token"].asString();
        }
        return user;
    }
}
#endif //MAIN_CC_AUTHMODELS_H
