//
// Created by epicmo on 22-10-14.
//

#ifndef MUAWEBBACKEND_TOKEN_H
#define MUAWEBBACKEND_TOKEN_H
#include <iostream>
namespace MUAWeb{
    class Token{
    public:
        std::string username;
        std::string token;
        Token(const std::string&);
        Token();//匿名Token
        //为True表示Token会被记录在Token池中
    };
}
#endif //MUAWEBBACKEND_TOKEN_H
