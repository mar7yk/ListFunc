//
// Created by Marty Kostov on 15.07.22.
//

#include "Engine.hpp"

[[noreturn]] void Engine::run() {
    while (true) {
        std::string line;
        std::cout << "> ";
        std::cin >> std::ws;
        getline(std::cin, line);

        if (tryToLoadingFileCommand(line)) {
            continue;
        }

        consoleHandle->executeLine(line);
    }
}

Engine::Engine() {
    parser = new Parser();
    consoleHandle = new ConsoleHandler(parser);
    fileHandler = new FileHandler(parser);
}

Engine::~Engine() {
    delete parser;
    delete consoleHandle;
    delete fileHandler;
}

bool Engine::tryToLoadingFileCommand(const std::string &line) {
    std::stringstream ss;
    ss << line;
    std::string load;
    ss >> load;

    if (load != "load") {
        return false;
    }
    ss >> std::ws;

    std::string fileName;
    std::getline(ss, fileName);
    std::cout << "Loading \""  << fileName << "\"...\n";

    fileHandler->executeFile(fileName);

    return true;
}
