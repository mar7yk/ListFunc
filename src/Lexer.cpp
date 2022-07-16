//
// Created by Marty Kostov on 15.07.22.
//

#include <sstream>
#include "Lexer.hpp"

std::vector<Token>* Lexer::getTokens(std::string &inProgram) const {
    auto* tokens = new std::vector<Token>;

    std::istringstream inProgramStream(inProgram);


    std::string word;
    while ( inProgramStream >> word ) {
        Token token;
        token.value = word;

        if (operators.find(word) != operators.end()) {
            token.type = TokenType::OPERATOR;

        } else if ( isNumber(word) ) {
            token.type = TokenType::NUMBER;

        } else if ( isArgument(word) ) {
            token.type = TokenType::ARGUMENT;

        } else if ( isIdentifier(word) ) {
            token.type = TokenType::IDENTIFIER;

        } else {
            delete tokens;
            return nullptr;
        }
        tokens->push_back(token);
    }


    return tokens;
}

bool Lexer::isNumber(const std::string& word) {
    bool haveDot = false;

    for (int i = 0; i < word.length(); ++i) {
        if (!isdigit(word[i])) {
            if(word[i] == '.') {
                if(haveDot) {
                    return false;
                } else {
                    haveDot = true;
                }
            } else {
                return false;
            }
        }
    }

    return true;
}

bool Lexer::isArgument(const std::string &word) {
    if (word[0] != '#') {
        return false;
    }

    for (int i = 1; i < word.length(); ++i) {
        if (!isdigit(word[i])) {
            return false;
        }
    }

    return true;
}

bool Lexer::isIdentifier(const std::string &word) {
    if ( !isalpha(word[0]) && word[0] != '_' ) {
        return false;
    }

    for (int i = 1; i < word.length(); i++) {
        if ( !isalnum(word[0]) && word[0] != '_' ) {
            return false;
        }
    }

    return true;
}
