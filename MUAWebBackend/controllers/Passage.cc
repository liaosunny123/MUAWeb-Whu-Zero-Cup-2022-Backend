#include "Passage.h"
#include "TokenDictionary.h"
#include "UserController.h"
#include "DataController.h"
#include "JsonError.h"
void Passage::GetPassageList(JsonModels::Passage::GetPassageList &&pGetPassageList,std::function<void(const HttpResponsePtr &)> &&callback,std::string category) const {
    Json::Value json;
    int number = DataController::getPassageNumber((Model::Category)std::stoi(category));
    Model::Passage* Passage = DataController::getFullPassageList((Model::Category)std::stoi(category),number);
    for(int i = 0;i < number;i++){
        Json::Value jsons;
        jsons["pid"] = Passage[i].pid;
        jsons["name"] = Passage[i].author;
        jsons["author"] = Passage[i].author;
        jsons["time"] = Passage[i].datetime;
        json["Passage"][i] = jsons;
        }
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void Passage::GetPassageContent(JsonModels::Passage::GetPassageContent &&pGetPassageContent , std::function<void (const HttpResponsePtr &)> &&callback,std::string category,std::string pid) const{
    Json::Value json;
    Model::Passage Passage = DataController::getPassage((Model::Category)std::stoi(category),std::stoi(pid));
    json["title"] = Passage.title;
    json["content"] = Passage.content;
    json["author"] = Passage.author;
    json["time"] = Passage.datetime;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void Passage::CreatePassage(JsonModels::Passage::CreatePassage &&pCreatePassage , std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pCreatePassage.username)){
        LOG_WARN << "User try to createPassage without Token. Username:" << pCreatePassage.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pCreatePassage.username).token != pCreatePassage.token){
        LOG_WARN << "User try to createPassage without RightToken" << pCreatePassage.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }
    Json::Value json;
    MUAWeb::Model::Passage passage((Model::Category)std::stoi(pCreatePassage.category),pCreatePassage.createtime,pCreatePassage.username,pCreatePassage.title,pCreatePassage.content);
    DataController::addPassage(passage);
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k200OK);
    callback(resp);
}
void Passage::RemovePassage(JsonModels::Passage::RemovePassage &&pRemovePassage , std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pRemovePassage.username)){
        LOG_WARN << "User try to createPassage without Token. Username:" << pRemovePassage.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pRemovePassage.username).token != pRemovePassage.token){
        LOG_WARN << "User try to createPassage without RightToken" << pRemovePassage.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }
    Json::Value json;
    Model::Passage Passage(pRemovePassage.pid,(Model::Category)std::stoi(pRemovePassage.category));
    DataController::removePassage(Passage);
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k200OK);
    callback(resp);
}