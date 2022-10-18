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
        static int64_t getRestTime(const std::string&);
        static int64_t getRestTime(const Token&);
        static void freshToken(const std::string&);
        static void freshToken(const Token&);
        static void deleteTokenFromListener(const std::string&);
        static void deleteTokenFromListener(const Token&);
        static void addTokenToListener(const std::string&);
        static void addTokenToListener(const Token&);
        static void checkTokenStatus(const std::string&);
        static void checkTokenStatus(const Token&);
        static bool isExisted(const std::string&);
        static bool isExisted(const Token&);
        static void disposeToken(const std::string&);
        static void disposeToken(const Token&);
    };
}
#endif //MAIN_CC_TOKENLISTENER_H
