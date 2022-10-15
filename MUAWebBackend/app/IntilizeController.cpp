//
// Created by epicmo on 22-10-15.
//
#include <iostream>
#include <json/json.h>
#include <fstream>
#include "mysql/mysql.h"
#include <trantor/utils/Logger.h>
#include "IntilizeController.h"
namespace MUAWeb{
    bool IntilizeController::Intilize() {
        std::ifstream ifs;
        ifs.open("wenben.txt",std::ios::in);
        if(!ifs.is_open())
        {
            LOG_FATAL << "Cannot open database.json. Does it exist? Does MUAWeb have the right to read it?";
            return false;
        }
        char buf[1024]={0};
        while(ifs >> buf);
        Json::Value config = (Json::Value)buf;
        strcpy(&IntilizeController::DBUser,config["DBUser"].asCString());
        strcpy(&IntilizeController::DBPassword,config["DBPassword"].asCString());
        strcpy(&IntilizeController::DBTable,config["DBTable"].asCString());
        strcpy(&IntilizeController::DBUrl,config["DBUrl"].asCString());
        MYSQL mysql;
        mysql_init(&mysql);
        if(!mysql_real_connect(&mysql,&IntilizeController::DBUrl,&IntilizeController::DBUser,&IntilizeController::DBPassword,&IntilizeController::DBTable,(int)IntilizeController::DBPort,NULL,0))
            return false;
        mysql_close(&mysql);
        return true;
    }
}