//
// Created by epicmo on 22-10-15.
//
#include <iostream>
#include <json/json.h>
#include "mysql/mysql.h"
#include <trantor/utils/Logger.h>
#include <fstream>
#include "IntilizeController.h"
#include "TokenDictionary.h"
namespace MUAWeb{
    std::string IntilizeController::DBUrl;
    std::string IntilizeController::DBUser;
    std::string IntilizeController::DBPassword;
    int IntilizeController::DBPort;
    std::string IntilizeController::DBTable;
    bool IntilizeController::Intilize() {
        Json::Reader reader;
        Json::Value config;
        std::string data;
        std::ifstream ifs("database.json", std::ios::binary);
        if (!ifs.is_open()){
            LOG_FATAL << "database.json cannot be opened.";
            return false;
        }
        if (reader.parse(ifs,config)){
            LOG_WARN << "database.json Format Error";
            return false;
        } else{
            IntilizeController::DBUrl = config["DBUrl"].asString();
            IntilizeController::DBPassword = config["DBPassword"].asString();
            IntilizeController::DBUser = config["DBUser"].asString();
            IntilizeController::DBTable = config["DBTable"].asString();
            IntilizeController::DBPort = config["DBPort"].asInt();
            MYSQL mysql;
            mysql_init(&mysql);
            if(!mysql_real_connect(&mysql,
                                   IntilizeController::DBUrl.c_str(),
                                   IntilizeController::DBUser.c_str(),
                                   IntilizeController::DBPassword.c_str(),
                                   IntilizeController::DBTable.c_str(),
                                   IntilizeController::DBPort,
                                   nullptr,
                                   0)){
                LOG_FATAL << "Cannot connect to SQLServer";
                mysql_close(&mysql);
                return false;
            }else{
                mysql_close(&mysql);
                return true;
            }

        }

    }
    void IntilizeController::EndRun() {
        TokenDictionary::removeAllToken();
    }
}