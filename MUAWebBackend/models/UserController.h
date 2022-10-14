//
// Created by epicmo on 22-10-14.
//

#ifndef MAIN_CC_USERCONTROLLER_H
#define MAIN_CC_USERCONTROLLER_H
#include "User.h"
namespace MUAWeb{
    class UserController{
    public:
        static void deleteUser(User);
        static void createUser(User);
        static void editPassword(User,std::string);
    };
}
#endif //MAIN_CC_USERCONTROLLER_H
