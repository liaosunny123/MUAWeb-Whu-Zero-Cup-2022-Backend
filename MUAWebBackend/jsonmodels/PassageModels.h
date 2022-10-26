//
// Created by epicmo on 22-10-25.
//

#ifndef MAIN_CC_PASSAGEMODELS_H
#define MAIN_CC_PASSAGEMODELS_H
#include <iostream>
#include <drogon/HttpRequest.h>
namespace MUAWeb::JsonModels::Passage{
    struct GetPassageList{
    };
    struct GetPassageContent{
    };
    struct CreatePassage{
        std::string username;
        std::string token;
        std::string title;
        std::string createtime;
        std::string content;
        std::string category;
    };
    struct RemovePassage{
        std::string username;
        std::string token;
        std::string category;
        int pid;
    };
}
namespace drogon{
    template <>
    inline MUAWeb::JsonModels::Passage::GetPassageList fromRequest(const HttpRequest &req){
        MUAWeb::JsonModels::Passage::GetPassageList temp;
        return temp;
    }
    template <>
    inline MUAWeb::JsonModels::Passage::GetPassageContent fromRequest(const HttpRequest &req){
        MUAWeb::JsonModels::Passage::GetPassageContent temp;
        return temp;
    }
    template <>
    inline MUAWeb::JsonModels::Passage::CreatePassage fromRequest(const HttpRequest &req){
        const auto& json = req.getJsonObject();
        MUAWeb::JsonModels::Passage::CreatePassage passage;
        if (json){
            passage.username = (*json)["username"].asString();
            passage.token = (*json)["token"].asString();
            passage.title = (*json)["title"].asString();
            passage.content = (*json)["content"].asString();
            passage.createtime = (*json)["createtime"].asString();
            passage.category = (*json)["category"].asString();
        }
        return passage;
    }
    template <>
    inline MUAWeb::JsonModels::Passage::RemovePassage fromRequest(const HttpRequest &req){
        const auto& json = req.getJsonObject();
        MUAWeb::JsonModels::Passage::RemovePassage passage;
        if (json){
            passage.username = (*json)["username"].asString();
            passage.token = (*json)["token"].asString();
            passage.pid = (*json)["pid"].asInt();
            passage.category = (*json)["category"].asString();
        }
        return passage;
    }
}
#endif //MAIN_CC_PASSAGEMODELS_H
