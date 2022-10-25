//
// Created by epicmo on 22-10-15.
//
#include "Passage.h"

#include <utility>
namespace MUAWeb::Model{
    Passage::Passage(int pid,Model::Category category,std::string title,std::string content,const std::string& editor,std::string datetime) {
        this->pid = pid;
        this->category = category;
        this->datetime = std::move(datetime);
        this->author = author;
        this->title = std::move(title);
        this->content = std::move(content);
    }
    Passage::Passage() {

    }
    Passage::Passage(Model::Category category,std::string title,std::string content,const std::string& editor,std::string datetime) {
        this->category = category;
        this->datetime = std::move(datetime);
        this->author = author;
        this->title = std::move(title);
        this->content = std::move(content);
    }
}