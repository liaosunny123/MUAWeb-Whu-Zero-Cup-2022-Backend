//
// Created by epicmo on 22-10-18.
//

#ifndef MAIN_CC_TOKENLISTENER_H
#define MAIN_CC_TOKENLISTENER_H
#include "TokenDictionary.h"
#include <unordered_map>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
namespace MUAWeb{
    class TokenListener{
    private:
        static std::unordered_map<std::string,boost::posix_time::ptime> expectAutoDispose;
    public:
        [[noreturn]] static void startListenerProcess();
        static void endListenerProcess();
        static int64_t getRestTime(std::string);
        static int64_t getRestTime(Token);
        static void freshToken(std::string);
        static void freshToken(Token);
        static void deleteTokenFromListener(std::string);
        static void deleteTokenFromListener(Token);
        static void addTokenToListener(std::string);
        static void addTokenToListener(Token);
        static void checkTokenStatus(std::string);
        static void checkTokenStatus(Token);
        static bool isExisted(std::string);
        static bool isExisted(Token);
        static void disposeToken(std::string);
        static void disposeToken(Token);
    };
}
#endif //MAIN_CC_TOKENLISTENER_H
