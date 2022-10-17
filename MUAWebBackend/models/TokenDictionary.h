//
// Created by epicmo on 22-10-14.
//

#ifndef MUAWEBBACKEND_TOKENDICTIONARY_H
#define MUAWEBBACKEND_TOKENDICTIONARY_H
#include <iostream>
#include <unordered_map>
#include "Token.h"
namespace MUAWeb{
    class TokenDictionary{
    private:
        static std::unordered_map<std::string,Token> list;
    public:
        static void addToken(Token);
        static void removeToken(Token);
        static void removeTokenAt(std::string);
        static bool isExist(Token);//Token是否存在
        static bool hasToken(std::string);//判断用户是否有非匿名化的Token
        static Token getToken(std::string);
        static void removeAllToken();
    };
}
#endif //MUAWEBBACKEND_TOKENDICTIONARY_H
