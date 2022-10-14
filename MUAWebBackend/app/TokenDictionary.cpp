//
// Created by epicmo on 22-10-14.
//
#include "TokenDictionary.h"
namespace MUAWeb{
    std::unordered_map<std::string,Token> TokenDictionary::list;
    void TokenDictionary::addToken(Token token){
        list.insert(std::pair<std::string,Token>(token.username,token));
    }
    void TokenDictionary::removeTokenAt(std::string tokenname){
        auto iter = list.find(tokenname);
        if (iter != list.end())
            list.erase(iter);
    }
    bool TokenDictionary::isExist(Token token){
        auto iter = list.find(token.username);
        if (iter != list.end())
            return true;
        else
            return false;
    }
    bool TokenDictionary::hasToken(std::string username){
        auto iter = list.find(username);
        if (iter != list.end())
            return true;
        else
            return false;
    }
    Token TokenDictionary::getToken(std::string username){
        auto iter = list.find(username);
        if (iter != list.end())
            return iter->second;
        else
            return new Token();
    }
    void TokenDictionary::removeToken(Token token){
        auto iter = list.find(token.username);
        if (iter != list.end())
            list.erase(iter);
    }
}