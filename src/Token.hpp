//
// Created by Marty Kostov on 16.07.22.
//

#ifndef LISTFUNC_TOKEN_HPP
#define LISTFUNC_TOKEN_HPP


#include <c++/v1/string>

enum class TokenType {
    NUMBER = 0,
    ARGUMENT,
    OPERATOR,
    IDENTIFIER,
};

struct Token {
    TokenType type;
    std::string value;
};


#endif //LISTFUNC_TOKEN_HPP
