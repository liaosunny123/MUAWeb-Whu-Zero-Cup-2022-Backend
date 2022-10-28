//
// Created by epicmo on 22-10-26.
//

#ifndef MAIN_CC_SEARCHMODELS_H
#define MAIN_CC_SEARCHMODELS_H
#include <iostream>
#include <drogon/HttpRequest.h>
namespace MUAWeb::JsonModels::Search{
    struct Search{
    };
}
namespace drogon {
    template<>
    inline MUAWeb::JsonModels::Search::Search fromRequest(const HttpRequest &req) {
        MUAWeb::JsonModels::Search::Search temp;
        return temp;
    }
}
#endif //MAIN_CC_SEARCHMODELS_H
