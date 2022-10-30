#include "Banner.h"
#include "TokenDictionary.h"
#include "JsonError.h"
#include "DataController.h"
#include "UserController.h"

// Add definition of your processing function here
void Banner::CreateBanner(JsonModels::Banner::CreateBanner &&pCreateBanner , std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pCreateBanner.username)){
        LOG_WARN << "User try to createBanner without Token. Username:" << pCreateBanner.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pCreateBanner.username).token != pCreateBanner.token){
        LOG_WARN << "User try to createBanner without RightToken" << pCreateBanner.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    DataController::createBanner(pCreateBanner.position,pCreateBanner.img);
    Json::Value json;
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k204NoContent);
    callback(resp);
}
void Banner::RemoveBanner(JsonModels::Banner::RemoveBanner &&pRemoveBanner , std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pRemoveBanner.username)){
        LOG_WARN << "User try to removeBanner without Token. Username:" << pRemoveBanner.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pRemoveBanner.username).token != pRemoveBanner.token){
        LOG_WARN << "User try to removeBanner without RightToken" << pRemoveBanner.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    DataController::removeBanner(pRemoveBanner.pid);
    Json::Value json;
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k204NoContent);
    callback(resp);
}
void Banner::GetBanner(JsonModels::Banner::GetBanner &&pGetBanner , std::function<void (const HttpResponsePtr &)> &&callback,std::string position) const{
    Json::Value json;
    int number = DataController::getBannerNumber(position);
    Model::Banner* banner = DataController::getBanner(position,number);
    for(int i = 0;i < number;i++){
        Json::Value jsons;
        jsons["pid"] = banner[i].pid;
        jsons["img"] = banner[i].img;
        json["banner"][i] = jsons;
    }
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}