//
// Created by epicmo on 22-10-15.
//
#include "School.h"

#include <utility>
namespace MUAWeb::Model{
    School::School(int pid,std::string url,std::string title,std::string content,std::string editor,std::string datetime) {
        this->pid = pid;
        this->url = std::move(url);
        this->datetime = std::move(datetime);
        this->author = author;
        this->title = std::move(title);
        this->content = std::move(content);
    }
    School::School() = default;
    School::School(std::string url,std::string title,std::string content,std::string editor,std::string datetime) {
        this->url = std::move(url);
        this->datetime = std::move(datetime);
        this->author = author;
        this->title = std::move(title);
        this->content = std::move(content);
    }
}