//
// Created by epicmo on 22-10-15.
//

#ifndef MAIN_CC_INTILIZECONTROLLER_H
#define MAIN_CC_INTILIZECONTROLLER_H
#include <iostream>
#include "Category.h"
namespace MUAWeb{
    class IntilizeController{
    public:
        MUAWeb::Model::DatabaseType databaseType;
        std::string DBUrl;
        std::string DBUser;
        std::string DBPassword;
        std::string DBPort;
        std::string DBTable;
        static void Intilize();
    };
}
#endif //MAIN_CC_INTILIZECONTROLLER_H
