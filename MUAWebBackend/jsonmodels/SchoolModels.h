//
// Created by epicmo on 22-10-18.
//

#ifndef MAIN_CC_SCHOOLMODELS_H
#define MAIN_CC_SCHOOLMODELS_H
#include <iostream>
#include <drogon/HttpRequest.h>
namespace MUAWeb::JsonModels::School{
    struct GetSchoolList{
    };
    struct GetSchoolContent{
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
namespace drogon{
    template <>
    inline MUAWeb::JsonModels::School::GetSchoolList fromRequest(const HttpRequest &req){
        MUAWeb::JsonModels::School::GetSchoolList temp;
        return temp;
    }
    template <>
    inline MUAWeb::JsonModels::School::GetSchoolContent fromRequest(const HttpRequest &req){
        MUAWeb::JsonModels::School::GetSchoolContent temp;
        return temp;
    }
    template <>
    inline MUAWeb::JsonModels::School::CreateSchool fromRequest(const HttpRequest &req){
        const auto& json = req.getJsonObject();
        MUAWeb::JsonModels::School::CreateSchool passage;
        if (json){
            passage.username = (*json)["username"].asString();
            passage.token = (*json)["token"].asString();
            passage.title = (*json)["title"].asString();
            passage.content = (*json)["content"].asString();
            passage.createtime = (*json)["createtime"].asString();
            passage.img = (*json)["img"].asString();
        }
        return passage;
    }
}
#endif //MAIN_CC_SCHOOLMODELS_H
