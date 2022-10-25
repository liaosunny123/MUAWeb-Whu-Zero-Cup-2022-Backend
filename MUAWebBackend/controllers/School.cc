#include "School.h"
#include "DataController.h"
#include "TokenDictionary.h"
#include "UserController.h"
#include "JsonError.h"

// Add definition of your processing function here

void School::GetSchoolList(JsonModels::School::GetSchoolList &&pGetSchoolList , std::function<void (const HttpResponsePtr &)> &&callback) const{
    Json::Value json;
    int number = DataController::getSchoolNumber();
    Model::School* school = DataController::getFullSchoolList(number);
    for(int i = 0;i < number;i++){
        Json::Value jsons;
        jsons["index"] = school[i].pid;
        jsons["name"] = school[i].author;
        jsons["img"] = school[i].url;
        json["school"][i] = jsons;
    }
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void School::GetSchoolContent(JsonModels::School::GetSchoolContent &&pGetSchoolContent , std::function<void (const HttpResponsePtr &)> &&callback,std::string pid) const{
    Json::Value json;
    Model::School school = DataController::getSchool(std::stoi(pid));
    json["title"] = school.title;
    json["content"] = school.content;
    json["author"] = school.author;
    json["time"] = school.datetime;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void School::CreateSchool(JsonModels::School::CreateSchool &&pCreateSchool , std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pCreateSchool.username)){
        LOG_WARN << "User try to createSchool without Token. Username:" << pCreateSchool.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pCreateSchool.username).token != pCreateSchool.token){
        LOG_WARN << "User try to createSchool without RightToken" << pCreateSchool.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }
    Json::Value json;
    MUAWeb::Model::School school(pCreateSchool.img,pCreateSchool.createtime,pCreateSchool.username,pCreateSchool.title,pCreateSchool.content);
    DataController::addSchool(school);
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k200OK);
    callback(resp);
}