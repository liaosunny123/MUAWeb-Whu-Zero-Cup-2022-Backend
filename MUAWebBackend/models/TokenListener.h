//
// Created by epicmo on 22-10-18.
//

#ifndef MAIN_CC_TOKENLISTENER_H
#define MAIN_CC_TOKENLISTENER_H
#include "TokenDictionary.h"
namespace MUAWeb{
    class TokenListener{
    public:
        static void getRestTime(std::string);
        static void getRestTime(Token);
        static void freshToken(std::string);
        static void freshToken(Token);
        static void deleteTokenFromListener(std::string);
        static void deleteTokenFromListener(Token);
        static void addTokenToListener(std::string);
        static void addTokenToListener(Token);
        static void checkTokenStatus(std::string);
        static void checkTokenStatus(Token);
        static void disposeToken(std::string);
        static void disposeToken(Token);
    };
}
#endif //MAIN_CC_TOKENLISTENER_H
