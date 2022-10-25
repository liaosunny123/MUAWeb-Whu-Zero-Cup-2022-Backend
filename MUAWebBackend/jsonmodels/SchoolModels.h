//
// Created by epicmo on 22-10-18.
//

#ifndef MAIN_CC_SCHOOLMODELS_H
#define MAIN_CC_SCHOOLMODELS_H
#include <iostream>
namespace MUAWeb::JsonModels::Auth{
    struct GetSchoolList{
    };
    struct GetSchoolContent{
        int pid;
    };
    struct CreateSchool{
        std::string username;
        std::string token;
        std::string title;
        std::string createtime;
        std::string content;
        std::string img;
    };
}
#endif //MAIN_CC_SCHOOLMODELS_H
