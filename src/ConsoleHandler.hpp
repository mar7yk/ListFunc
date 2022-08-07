//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_CONSOLEHANDLER_HPP
#define LISTFUNC_CONSOLEHANDLER_HPP


#include "Parser.hpp"

class ConsoleHandler {
    Parser *parser;
public:
    explicit ConsoleHandler(Parser *parser);

    void executeLine(const std::string &line); ///< execute single line string
};


#endif //LISTFUNC_CONSOLEHANDLER_HPP
