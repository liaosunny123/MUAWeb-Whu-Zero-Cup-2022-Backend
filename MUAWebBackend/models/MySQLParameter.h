//
// Created by epicmo on 22-10-15.
//

#ifndef MAIN_CC_MYSQLPARAMETER_H
#define MAIN_CC_MYSQLPARAMETER_H
#include <iostream>
#include <unordered_map>
namespace MUAWeb{
    class MySQLParameter{
    private:
        std::string sql;
        std::unordered_map<std::string,std::string> parametes;
    public:
        MySQLParameter(std::string);
        void addParameter(std::string,std::string);
        void removeParameter(std::string);
        std::string getSQL();
    };
}
#endif //MAIN_CC_MYSQLPARAMETER_H
