//
// Created by epicmo on 22-10-15.
//
#include "Passage.h"
namespace MUAWeb::Model{
    Passage::Passage(int pid,Model::Category category,std::string title,std::string content,std::string editor,std::string datetime) {
        this->pid = pid;
        this->category = category;
        this->datetime = datetime;
        this->author = author;
        this->title = title;
        this->content = content;
    }
    Passage::Passage() {

    }
}