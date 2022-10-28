//
// Created by epicmo on 22-10-26.
//

#ifndef MAIN_CC_SEARCH_H
#define MAIN_CC_SEARCH_H
#include "jsonmodels/SearchModels.h"
#include <drogon/HttpController.h>

using namespace drogon;
using namespace MUAWeb;
class Search : public drogon::HttpController<Search>{
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(Search::q, "/?q={content}", Post);
    METHOD_LIST_END
    void q(JsonModels::Search::Search &&pSearch , std::function<void (const HttpResponsePtr &)> &&callback,std::string q) const;
};
#endif //MAIN_CC_SEARCH_H
