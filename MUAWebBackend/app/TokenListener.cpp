//
// Created by epicmo on 22-10-18.
//
#include "TokenListener.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <trantor/utils/Logger.h>
namespace MUAWeb{
    std::unordered_map<std::string,boost::posix_time::ptime> TokenListener::expectAutoDispose;
    int64_t TokenListener::getRestTime(const std::string& username){
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        auto iter = expectAutoDispose.find(username);
        if (iter != expectAutoDispose.end()){
            boost::posix_time::ptime localtime = boost::posix_time::second_clock::local_time();
            boost::posix_time::time_duration td = iter->second - localtime;
            return td.total_seconds();
        }else{
            LOG_WARN << "Unsafe request from local server for checking unexisted token dispose time:" << username;
            return -1;
        }
    }
    int64_t TokenListener::getRestTime(const Token& token){
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        auto iter = expectAutoDispose.find(token.username);
        if (iter != expectAutoDispose.end()){
            boost::posix_time::ptime localtime = boost::posix_time::second_clock::local_time();
            boost::posix_time::time_duration td = iter->second - localtime;
            return td.total_seconds();
        }else{
            LOG_WARN << "Unsafe request from local server for checking unexisted token dispose time:" << token.username;
            return -1;
        }
    }
    void TokenListener::freshToken(const std::string& username){
        if (!TokenListener::isExisted(username)){
            LOG_WARN << "Unsafe request from local server for freshing unexisted token dispose time:" << username;
            return;
        }
        TokenListener::deleteTokenFromListener(username);
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        boost::posix_time::time_duration segment(24, 0, 0);
        boost::posix_time::ptime expectedtime = createtime + segment;
        expectAutoDispose.insert(std::pair<std::string,boost::posix_time::ptime>(username,expectedtime));
    }
    void TokenListener::freshToken(const Token& token){
        if (!TokenListener::isExisted(token)){
            LOG_WARN << "Unsafe request from local server for freshing unexisted token dispose time:" << token.username;
            return;
        }
        TokenListener::deleteTokenFromListener(token);
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        boost::posix_time::time_duration segment(24, 0, 0);
        boost::posix_time::ptime expectedtime = createtime + segment;
        expectAutoDispose.insert(std::pair<std::string,boost::posix_time::ptime>(token.username,expectedtime));
    }
    void TokenListener::deleteTokenFromListener(const std::string& username){
        auto iter = expectAutoDispose.find(username);
        if (iter != expectAutoDispose.end()){
            expectAutoDispose.erase(iter);
        }else{
            LOG_WARN << "Unsafe request from local server for deleting unexisted token dispose time:" << username;
            return;
        }
    }
    void TokenListener::deleteTokenFromListener(const Token& token){
        auto iter = expectAutoDispose.find(token.username);
        if (iter != expectAutoDispose.end()){
            expectAutoDispose.erase(iter);
        }else{
            LOG_WARN << "Unsafe request from local server for deleting unexisted token dispose time:" << token.username;
            return;
        }
    }
    void TokenListener::addTokenToListener(const std::string& username){
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        boost::posix_time::time_duration segment(24, 0, 0);
        boost::posix_time::ptime expectedtime = createtime + segment;
        expectAutoDispose.insert(std::pair<std::string,boost::posix_time::ptime>(username,expectedtime));
    }
    void TokenListener::addTokenToListener(const Token& token){
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        boost::posix_time::time_duration segment(24, 0, 0);
        boost::posix_time::ptime expectedtime = createtime + segment;
        expectAutoDispose.insert(std::pair<std::string,boost::posix_time::ptime>(token.username,expectedtime));
    }
    void TokenListener::checkTokenStatus(const std::string& username){
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        auto iter = expectAutoDispose.find(username);
        if (iter != expectAutoDispose.end()){
            boost::posix_time::ptime localtime = boost::posix_time::second_clock::local_time();
            boost::posix_time::time_duration td = iter->second - localtime;
            if (td.total_seconds() <= 0){
                expectAutoDispose.erase(iter);
            }
        }else{
            LOG_WARN << "Unsafe request from local server for checking unexisted token dispose time:" << username;
            return;
        }
    }
    void TokenListener::checkTokenStatus(const Token& token){
        boost::posix_time::ptime createtime = boost::posix_time::second_clock::local_time();
        auto iter = expectAutoDispose.find(token.username);
        if (iter != expectAutoDispose.end()){
            boost::posix_time::ptime localtime = boost::posix_time::second_clock::local_time();
            boost::posix_time::time_duration td = iter->second - localtime;
            if (td.total_seconds() <= 0){
                expectAutoDispose.erase(iter);
            }
        }else{
            LOG_WARN << "Unsafe request from local server for checking unexisted token dispose time:" << token.username;
            return;
        }
    }
    void TokenListener::disposeToken(const std::string& username){
        TokenDictionary::removeTokenAt(username);
    }
    void TokenListener::disposeToken(const Token& token){
        TokenDictionary::removeToken(token);
    }

    [[noreturn]] void TokenListener::startListenerProcess(){
        while(true){
            for (const auto& item:expectAutoDispose) {
                TokenListener::checkTokenStatus(item.first);
            }
            sleep(30);
        }
    }
    void TokenListener::endListenerProcess(){

    }
    bool TokenListener::isExisted(const std::string& username){
        auto iter = expectAutoDispose.find(username);
        if (iter != expectAutoDispose.end()){
            return true;
        }else{
            return false;
        }
    }
    bool TokenListener::isExisted(const Token& token){
        auto iter = expectAutoDispose.find(token.username);
        if (iter != expectAutoDispose.end()){
            return true;
        }else{
            return false;
        }
    }
}