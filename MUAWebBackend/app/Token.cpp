//
// Created by epicmo on 22-10-14.
//
#include "Token.h"
#include "Utility.h"
#include "TokenDictionary.h"
#include <trantor/utils/Logger.h>
namespace MUAWeb{
    Token::Token(std::string username){
        this->username = username;
        this->token = Utility::generateUnsignedUUID();
        if (TokenDictionary::isExist(username)){
            LOG_INFO << "The same user trys to login in.Tick the former User:" << username;
            TokenDictionary::removeTokenAt(username);
        }
        TokenDictionary::addToken(*this);
    }
    Token::Token(){
        this->username = "";
        this->token = Utility::generateUnsignedUUID();
    }
}