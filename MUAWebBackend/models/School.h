//
// Created by epicmo on 22-10-14.
//

#ifndef MAIN_CC_SCHOOL_H
#define MAIN_CC_SCHOOL_H
#include <iostream>
#include "Category.h"
namespace MUAWeb::Model{
    class School{
    public:
        int pid;
        Category category = MUAWeb::Model::Category::schooldescription;
        std::string title;
        std::string author;
        std::string datetime;
        std::string content;
        std::string url;
        School();
        School(int,std::string,std::string,std::string,std::string,std::string);
    };
}
#endif //MAIN_CC_SCHOOL_H
