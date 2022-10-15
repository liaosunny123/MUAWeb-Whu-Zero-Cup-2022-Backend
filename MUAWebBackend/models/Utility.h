//
// Created by epicmo on 22-10-14.
//

#ifndef MUAWEBBACKEND_UTILITY_H
#define MUAWEBBACKEND_UTILITY_H
#include <iostream>
#include "User.h"
namespace MUAWeb{
    class Utility{
    public:
        static std::string generateUUID();
        static std::string generateUnsignedUUID();
        static std::string& replace(std::string& str, const std::string& old_value, const std::string& new_value);
    };
}
#endif //MUAWEBBACKEND_UTILITY_H
