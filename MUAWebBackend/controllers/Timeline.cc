#include "Timeline.h"
#include "TokenDictionary.h"
#include "JsonError.h"
#include "DataController.h"
#include "UserController.h"
// Add definition of your processing function here
void Timeline::CreateTimeline(JsonModels::Timeline::CreateTimeline &&pCreateTimeline , std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pCreateTimeline.username)){
        LOG_WARN << "User try to createTimeline without Token. Username:" << pCreateTimeline.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pCreateTimeline.username).token != pCreateTimeline.token){
        LOG_WARN << "User try to createTimeline without RightToken" << pCreateTimeline.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    DataController::createTimeline(pCreateTimeline.name,pCreateTimeline.description,pCreateTimeline.time);
    Json::Value json;
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k204NoContent);
    callback(resp);
}
void Timeline::RemoveTimeline(JsonModels::Timeline::RemoveTimeline &&pRemoveTimeline , std::function<void (const HttpResponsePtr &)> &&callback) const{
    if (!TokenDictionary::hasToken(pRemoveTimeline.username)){
        LOG_WARN << "User try to removeTimeline without Token. Username:" << pRemoveTimeline.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    if (TokenDictionary::getToken(pRemoveTimeline.username).token != pRemoveTimeline.token){
        LOG_WARN << "User try to removeTimeline without RightToken" << pRemoveTimeline.username;
        callback(MUAWeb::JsonError::ErrorResponse(403,"用户权限效验失败"));
        return;
    }

    DataController::removeTimeline(pRemoveTimeline.pid);
    Json::Value json;
    json["status"] = true;
    auto resp=HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(drogon::k204NoContent);
    callback(resp);
}
void Timeline::GetTimeline(JsonModels::Timeline::GetTimeline &&pGetTimeline , std::function<void (const HttpResponsePtr &)> &&callback) const{
    Json::Value json;
    int number = DataController::getTimelineNumber();
    Model::Timeline* Timeline = DataController::getTimeline(number);
    for(int i = 0;i < number;i++) {
        Json::Value jsons;
        jsons["pid"] = Timeline[i].pid;
        jsons["name"] = Timeline[i].name;
        jsons["description"] = Timeline[i].description;
        jsons["time"] = Timeline[i].time;
        json["timeline"][i] = jsons;
    }
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}