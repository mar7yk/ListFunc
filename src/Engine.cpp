//
// Created by Marty Kostov on 15.07.22.
//

#include "Engine.hpp"

void Engine::run() {
    while (true) {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        consoleHandle->executeLine(line);
    }
}

Engine::Engine() {
    parser = new Parser();
    consoleHandle = new ConsoleHandle(parser);
}

Engine::~Engine() {
    delete parser;
    delete consoleHandle;
}
