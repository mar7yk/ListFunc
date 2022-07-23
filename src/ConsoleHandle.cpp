//
// Created by Marty Kostov on 23.07.22.
//

#include "ConsoleHandle.hpp"

ConsoleHandle::ConsoleHandle(Parser *parser) : parser(parser) {}

void ConsoleHandle::executeLine(const std::string &line) {
    parser->enterText(line);

    IExecutable* expression = parser->getExecutable();
    if (!expression) {
        return;
    }
    std::string result = expression->execute();
    delete expression;

    std::cout << result;
}
