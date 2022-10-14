//
// Created by epicmo on 22-10-14.
//
#include "Token.h"
#include "Utility.h"
#include "TokenDictionary.h"
namespace MUAWeb{
    Token::Token(std::string username){
        this->username = username;
        this->token = Utility::generateUUID();
        TokenDictionary::addToken(*this);
    }
    Token::Token(){
        this->username = "";
        this->token = Utility::generateUUID();
    }
}