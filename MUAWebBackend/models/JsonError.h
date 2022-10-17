//
// Created by epicmo on 22-10-16.
//

#ifndef MAIN_CC_JSONERROR_H
#define MAIN_CC_JSONERROR_H
#include <iostream>
#include <json/json.h>
#include <drogon/HttpController.h>
namespace MUAWeb{
    class JsonError{
    public:
        static std::shared_ptr<drogon::HttpResponse> ErrorResponse(int,std::string);
    };
}
#endif //MAIN_CC_JSONERROR_H
