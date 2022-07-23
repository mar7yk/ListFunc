//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_CONSOLEHANDLE_HPP
#define LISTFUNC_CONSOLEHANDLE_HPP


#include "Parser.hpp"

class ConsoleHandle {
    Parser *parser;
public:
    explicit ConsoleHandle(Parser *parser);

    void executeLine(const std::string &line);
};


#endif //LISTFUNC_CONSOLEHANDLE_HPP
