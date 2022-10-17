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
        static std::string DBUrl;
        static std::string DBUser;
        static std::string DBPassword;
        static int DBPort;
        static std::string DBTable;
        static bool Intilize();
        static void EndRun();
    };
}
#endif //MAIN_CC_INTILIZECONTROLLER_H
