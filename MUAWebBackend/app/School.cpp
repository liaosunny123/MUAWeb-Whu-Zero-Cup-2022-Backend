//
// Created by epicmo on 22-10-15.
//
#include "School.h"
namespace MUAWeb::Model{
    School::School(int pid,std::string url,std::string title,std::string content,std::string editor,std::string datetime) {
        this->pid = pid;
        this->url = url;
        this->datetime = datetime;
        this->author = author;
        this->title = title;
        this->content = content;
    }
    School::School() {

    }
    School::School(std::string url,std::string title,std::string content,std::string editor,std::string datetime) {
        this->url = url;
        this->datetime = datetime;
        this->author = author;
        this->title = title;
        this->content = content;
    }
}