//
// Created by Marty Kostov on 15.07.22.
//

#ifndef LISTFUNC_LEXER_HPP
#define LISTFUNC_LEXER_HPP

#include <unordered_set>
#include <vector>

#include "Token.hpp"

class Lexer {
    std::unordered_set<std::string> operators = {"(", ")", ",", "[", "]", "->"};

    static bool isNumber(const std::string& word);
    static bool isArgument(const std::string& word);
    static bool isIdentifier(const std::string& word);

public:
    Lexer() = default;

    std::vector<Token>* getTokens(std::string &inProgram) const;
};


#endif //LISTFUNC_LEXER_HPP
