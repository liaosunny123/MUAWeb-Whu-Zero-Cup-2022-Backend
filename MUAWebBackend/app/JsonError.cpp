//
// Created by epicmo on 22-10-16.
//
#include "JsonError.h"
namespace MUAWeb{
    std::shared_ptr<drogon::HttpResponse> JsonError::ErrorResponse(int code, std::string cause) {
        Json::Value error;
        error["code"] = code;
        error["cause"] = cause;
        auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
        switch (code) {
            case 403:
                resp->setStatusCode(drogon::k403Forbidden);
                break;
            case 404:
                resp->setStatusCode(drogon::k404NotFound);
                break;
            case 500:
                resp->setStatusCode(drogon::k500InternalServerError);
                break;
            case 502:
                resp->setStatusCode(drogon::k502BadGateway);
                break;
            default:
                resp->setStatusCode(drogon::k503ServiceUnavailable);
                break;
        }

        return resp;
    }
}