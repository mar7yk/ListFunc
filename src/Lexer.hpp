//
// Created by Marty Kostov on 15.07.22.
//

#ifndef LISTFUNC_LEXER_HPP
#define LISTFUNC_LEXER_HPP

#include <unordered_set>
#include <vector>

#include "Token.hpp"

class Lexer {
    std::unordered_set<char> operatorsSymbols = {'(', ')', ',', '[', ']', '-', '>'};
    std::unordered_set<std::string> operators = {"(", ")", ",", "[" , "]", "->"};

    std::string inProgram;
    size_t index = 0;
    size_t line = 0;

    void cleanSpaces();
    Token getOperatorsToken();
    Token getNumbToken();
    Token getArgumentToken();
    Token getIdentifierToken();

public:
    Lexer() = default;

    void enterText(const std::string &inProgram);
    Token getNextToken();
};


#endif //LISTFUNC_LEXER_HPP
