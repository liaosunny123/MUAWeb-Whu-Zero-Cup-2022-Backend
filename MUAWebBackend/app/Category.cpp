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

MUAWeb::Model::Category MUAWeb::Model::StringToCategory(std::string category) {
    if (category == "activitydescription"){
        return Category::activitydescription;
    }else if(category == "othersdescription"){
        return Category::othersdescription;
    }else if(category == "schooldescription"){
        return Category::schooldescription;
    }else if(category == "projectdescription"){
        return Category::projectdescription;
    }else if(category == "rebuilddescription"){
        return Category::rebuilddescription;
    }else{
        LOG_WARN << "Error for check for unexisted model.Mock a data back to:";
        return Category::schooldescription;
    }

}