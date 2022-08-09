//
// Created by Marty Kostov on 15.07.22.
//

#ifndef LISTFUNC_LEXER_HPP
#define LISTFUNC_LEXER_HPP

#include <unordered_set>
#include <vector>

#include "Token.hpp"

///Transform a text to tokens
class Lexer {
    std::unordered_set<char> operatorsSymbols = {'(', ')', ',', '[', ']', '-', '>'};
    std::unordered_set<std::string> operators = {"(", ")", ",", "[" , "]", "->", "-"};

    std::string inProgram;
    size_t index = 0;
    bool isOnComment;

    ///move index while there is not whitespace on index position
    void cleanSpaces();

    ///@return operator token
    Token getOperatorsToken();

    ///@return number token
    Token getNumbToken();

    ///@return argument token
    Token getArgumentToken();

    ///@return identifier token
    Token getIdentifierToken();

public:
    Lexer() = default;

    ///add new text for executing
    void enterText(const std::string &text);

    ///@return pointer to new token
    Token getNextToken();
};


#endif //LISTFUNC_LEXER_HPP
