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
        Category category;
        std::string title;
        std::string author;
        std::string datetime;
        std::string content;
    };
}
#endif //MUAWEBBACKEND_PASSAGE_H
