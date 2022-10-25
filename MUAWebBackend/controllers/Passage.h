#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class Passage : public drogon::HttpController<Passage>
{
  public:
    METHOD_LIST_BEGIN

    METHOD_LIST_END

};
