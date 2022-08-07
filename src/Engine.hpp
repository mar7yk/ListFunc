//
// Created by Marty Kostov on 15.07.22.
//

#ifndef LISTFUNC_ENGINE_HPP
#define LISTFUNC_ENGINE_HPP

#include <sstream>

#include "ConsoleHandler.hpp"
#include "FileHandler.hpp"

class Engine {
    Parser *parser;
    ConsoleHandler *consoleHandle;
    FileHandler *fileHandler;

    bool tryToLoadingFileCommand(const std::string &line);

public:
    Engine();

    virtual ~Engine();

    [[noreturn]] void run(); ///< starting point
};


#endif //LISTFUNC_ENGINE_HPP
