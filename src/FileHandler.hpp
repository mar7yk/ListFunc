//
// Created by Marty Kostov on 1.08.22.
//

#ifndef LISTFUNC_FILEHANDLER_HPP
#define LISTFUNC_FILEHANDLER_HPP


#include <fstream>

#include "Parser.hpp"

///Handle code in a file
class FileHandler {
    Parser *parser;
public:
    explicit FileHandler(Parser *parser);

    void executeFile(const std::string &fileName); ///< execute file with name fileName
};


#endif //LISTFUNC_FILEHANDLER_HPP
