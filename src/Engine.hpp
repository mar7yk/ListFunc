//
// Created by Marty Kostov on 15.07.22.
//

#ifndef LISTFUNC_ENGINE_HPP
#define LISTFUNC_ENGINE_HPP

#include "ConsoleHandle.hpp"

class Engine {
    Parser *parser;
    ConsoleHandle *consoleHandle;

public:
    Engine();

    virtual ~Engine();

    void run();
};


#endif //LISTFUNC_ENGINE_HPP
