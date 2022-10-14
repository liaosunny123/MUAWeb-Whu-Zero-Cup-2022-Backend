//
// Created by epicmo on 22-10-14.
//
#include "UserController.h"
#include "DataController.h"
namespace MUAWeb{
    void UserController::deleteUser(User user){
        DataController::removeUser(user);
    }
    void UserController::createUser(User user){
        DataController::addUser(user);
    }
    void UserController::editPassword(User user,std::string passwd){
        DataController::editPassword(user,passwd);
    }
}