//
// Created by epicmo on 22-10-14.
//

#ifndef MUAWEBBACKEND_USER_H
#define MUAWEBBACKEND_USER_H
#include <iostream>
#include "Token.h"
namespace MUAWeb{
    class User{
    private:
        std::string username;
        std::string password;
        Token token;
    public:
        User();
        User(std::string,std::string);
        User(std::string,std::string,Token);
        std::string getUsername();
        std::string getPassword();
        bool isRoot();
        bool hasToken();
        bool verifyPassword();
        bool verifyToken();
        Token getToken();
        void disposeToken();
        void changePassword(std::string);
        void setToken(Token);
        void generateToken();
    };
}
#endif //MUAWEBBACKEND_USER_H
