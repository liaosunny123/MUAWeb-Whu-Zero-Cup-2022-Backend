//
// Created by epicmo on 22-10-14.
//
#include "Token.h"
#include "Utility.h"
namespace MUAWeb{
    Token::Token(std::string username){

    }
    Token::Token(){
        this->username = "";
        this->token = Utility::generateUUID();
    }
}