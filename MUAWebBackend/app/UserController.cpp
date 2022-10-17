//
// Created by epicmo on 22-10-14.
//
#include "UserController.h"

#include <utility>
#include "TokenDictionary.h"
#include "DataController.h"
namespace MUAWeb{
    void UserController::deleteUser(User user){
        DataController::removeUser(std::move(user));
    }
    void UserController::createUser(User user){
        DataController::addUser(std::move(user));
    }
    void UserController::editPassword(User user,std::string passwd){
        DataController::editPassword(std::move(user),std::move(passwd));
    }
    std::string UserController::getPassword(std::string username){
        return DataController::getPassword(std::move(username));
    }
    User UserController::getUser(const std::string& username){
        return *(new User(username,DataController::getPassword(username)));
    }
    User UserController::getUserFromDictionary(const std::string& username){
        return *(new User(username,DataController::getPassword(username),TokenDictionary::getToken(username)));
    }
    bool UserController::isExist(std::string username){
        if (DataController::getUser(std::move(username)).getUsername().empty())
            return false;
        else
            return true;
    }
}