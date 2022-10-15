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
        static char DBUrl;
        static char DBUser;
        static char DBPassword;
        static int DBPort;
        static char DBTable;
        static bool Intilize();
    };
}
#endif //MAIN_CC_INTILIZECONTROLLER_H
