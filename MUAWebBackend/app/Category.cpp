//
// Created by epicmo on 22-10-28.
//
#include <iostream>
#include "Category.h"
#include <trantor/utils/Logger.h>
std::string MUAWeb::Model::CategoryToString(MUAWeb::Model::Category category) {
    switch (category) {
        case Category::activitydescription:
            return "activitydescription";
        case Category::othersdescription:
            return "othersdescription";
        case Category::schooldescription:
            return "schooldescription";
        case Category::projectdescription:
            return "projectdescription";
        case Category::rebuilddescription:
            return "rebuilddescription";
        default:
            LOG_WARN << "MODEL ERROR for no entity.";
            return "";
    }
}