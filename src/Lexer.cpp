//
// Created by Marty Kostov on 15.07.22.
//

#include "Lexer.hpp"

void Lexer::enterText(const std::string &text) {
    this->inProgram = text;
    this->index = 0;
    this->isOnComment = false;
}

Token Lexer::getNextToken() {

    cleanSpaces();

    if (index == inProgram.length()) {
        return {TokenType::END, ""};
    }

    if (inProgram[index] == '/' && inProgram[index + 1] == '/') {
        index += 2;
        isOnComment = true;
        return getNextToken();
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
        return {TokenType::ERROR, "Not valid syntax!"};
    }
}

void Lexer::cleanSpaces() {
    while ( index < inProgram.size() && (isspace(inProgram[index]) || isOnComment)) {
        ++index;

        if (inProgram[index] == '\n') {
            isOnComment = false;
        }
    }
}

Token Lexer::getOperatorsToken() {
    std::string value;
    for (; index < inProgram.length(); ++index) {
        if(operatorsSymbols.find( inProgram[index] ) == operatorsSymbols.end()) {
            break;
        }

        value += inProgram[index];
    }

    while (!value.empty()) {
        if ( operators.find( value ) != operators.end() ) {
            return {TokenType::OPERATOR, value};
        }
        value.resize(value.size() - 1);
        --index;
    }

    return {TokenType::ERROR, "Not valid operator \"" + value + "\"!"};
}

Token Lexer::getNumbToken() {
    std::string value;
    bool haveDot = false;

    for (; index < inProgram.length(); ++index) {
        if (isdigit(inProgram[index])) {
            value += inProgram[index];

        } else if(inProgram[index] == '.') {
            if(haveDot) {
                return {TokenType::ERROR, "Not valid number \"" + value + "\"!"};

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
        return {TokenType::ERROR, "Not valid argument!"};
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
