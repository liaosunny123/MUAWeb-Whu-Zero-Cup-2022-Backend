//
// Created by epicmo on 22-10-14.
//

#ifndef MUAWEBBACKEND_PASSAGE_H
#define MUAWEBBACKEND_PASSAGE_H
#include <iostream>
#include "Category.h"
namespace MUAWeb::Model{
    class Passage{
    public:
        int pid;
        Model::Category category;
        std::string title;
        std::string author;
        std::string datetime;
        std::string content;
        Passage();
        Passage(int,Model::Category,std::string,std::string,std::string,std::string);
    };
}
#endif //MUAWEBBACKEND_PASSAGE_H
