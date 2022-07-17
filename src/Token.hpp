//
// Created by Marty Kostov on 16.07.22.
//

#ifndef LISTFUNC_TOKEN_HPP
#define LISTFUNC_TOKEN_HPP


#include <string>

enum class TokenType {
    END = 0,
    OPERATOR,
    NUMBER,
    ARGUMENT,
    IDENTIFIER,
    ERROR,
};

struct Token {
    TokenType type;
    std::string value;
};


#endif //LISTFUNC_TOKEN_HPP
