//
// Created by epicmo on 22-10-15.
//
#include <iostream>
#include "Utility.h"
#include "MySQLParameter.h"
namespace MUAWeb{
    MySQLParameter::MySQLParameter(std::string sql){
        this->sql = sql;
    }
    void MySQLParameter::addParameter(const std::string& paraname,std::string content){
        std::string temp;
        temp = Utility::replace(content,"'","''");
        this->parametes.insert(std::pair<std::string,std::string>(paraname,temp));
    }
    void MySQLParameter::removeParameter(const std::string& parname){
        auto iter = parametes.find(parname);
        if (iter != parametes.end())
            parametes.erase(iter);
    }
    std::string MySQLParameter::getSQL(){
        for (const std::pair<const std::basic_string<char>, std::basic_string<char>>& para:parametes) {
            sql = Utility::replace(sql,para.first,para.second);
        }
        return sql;
    }
}