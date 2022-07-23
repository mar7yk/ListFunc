//
// Created by Marty Kostov on 15.07.22.
//

#include "Lexer.hpp"

void Lexer::enterText(const std::string &inProgram) {
    this->inProgram = inProgram;
    this->index = 0;
    this->line = 0;
}

Token Lexer::getNextToken() {

    cleanSpaces();

    if (index == inProgram.length()) {
        return {TokenType::END, ""};
    }

    if (operatorsSymbols.find( inProgram[index] ) != operatorsSymbols.end()) {
        return getOperatorsToken();

    } else if ( isdigit( inProgram[index] ) ) {
        return getNumbToken();

    } else if ( inProgram[index] == '#' ) {
        ++index;
        return getArgumentToken();

    } else if ( isalpha(inProgram[0]) || inProgram[0] == '_' ) {
        return getIdentifierToken();

    } else {
        return {TokenType::ERROR, "Not valid syntax on line " + std::to_string(line) + "!"};
    }
}

void Lexer::cleanSpaces() {
    while (isspace(inProgram[index])) {
        if(inProgram[index] == '\n') {
            ++line;
        }
        ++index;
    }
}

Token Lexer::getOperatorsToken() {
    std::string value;
    for (; index < inProgram.length(); ++index) {
        if(operatorsSymbols.find( inProgram[index] ) != operatorsSymbols.end()) {
            value += inProgram[index];
            if ( operators.find( value ) != operators.end() ) {
                ++index;
                return {TokenType::OPERATOR, value};
            }
        } else {
            break;
        };
    }

    return {TokenType::ERROR, "Not valid operator \"" + value + "\" on line " + std::to_string(line) + "!"};
}

Token Lexer::getNumbToken() {
    std::string value;
    bool haveDot = false;

    for (; index < inProgram.length(); ++index) {
        if (isdigit(inProgram[index])) {
            value += inProgram[index];

        } else if(inProgram[index] == '.') {
            if(haveDot) {
                return {TokenType::ERROR, "Not valid number \"" + value + "\" on line " + std::to_string(line) + "!"};

            } else {
                haveDot = true;
                value += inProgram[index];
            }
        } else {
            break;
        }
    }

    return {TokenType::NUMBER, value};
}

Token Lexer::getArgumentToken() {
    std::string value;

    for (; index < inProgram.length() && isdigit(inProgram[index]); ++index) {
            value += inProgram[index];
    }

    if (value.length() == 0) {
        return {TokenType::ERROR, "Not valid argument on line " + std::to_string(line) + "!"};
    }

    return {TokenType::ARGUMENT, value};
}

Token Lexer::getIdentifierToken() {
    std::string value;

    for (; index < inProgram.length() && (isalnum(inProgram[index]) || inProgram[index] == '_'); ++index) {
        value += inProgram[index];
    }

    return {TokenType::IDENTIFIER, value};
}
