//
// Created by Marty Kostov on 1.08.22.
//

#ifndef LISTFUNC_FILEHANDLER_HPP
#define LISTFUNC_FILEHANDLER_HPP


#include <fstream>

#include "Parser.hpp"

class FileHandler {
    Parser *parser;
public:
    explicit FileHandler(Parser *parser);

    void executeFile(const std::string &fileName);
};


#endif //LISTFUNC_FILEHANDLER_HPP
