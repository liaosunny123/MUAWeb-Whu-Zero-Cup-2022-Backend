//
// Created by epicmo on 22-10-14.
//
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "Utility.h"
namespace MUAWeb{
    std::string Utility::generateUUID() {
        boost::uuids::uuid uid = boost::uuids::random_generator()();
        const std::string uid_str = boost::uuids::to_string(uid);
        return uid_str;
    }

    std::string Utility::generateUnsignedUUID() {
        boost::uuids::uuid uid = boost::uuids::random_generator()();
        std::string stru0 = boost::uuids::to_string(uid);
        stru0.erase(std::remove(stru0.begin(), stru0.end(), '-'), stru0.end());
        return stru0;
    }

    std::string& Utility::replace(std::string& str, const std::string& old_value, const std::string& new_value)
    {
        for(std::string::size_type pos(0); pos!=std::string::npos; pos+=new_value.length()) {
            if( (pos=str.find(old_value,pos))!=std::string::npos )
                str.replace(pos,old_value.length(),new_value);
            else break;
        }
        return str;
    }
}