//
// Created by Marty Kostov on 1.08.22.
//

#include "FileHandler.hpp"

FileHandler::FileHandler(Parser *parser) : parser(parser) {}

void FileHandler::executeFile(const std::string &fileName) {
    std::ifstream file(fileName);

    if(!file){
        std::cout <<"Error! The file cannot be opened.\n";
        return;
    }

    std::string line;
    size_t lineNum = 0;


        while (std::getline(file, line)) {
            ++lineNum;

            parser->enterText(line);
            try {
                IExecutable* expression = parser->getExecutable();
                if (!expression) {
                    continue;
                }
                expression->execute();
                delete expression;

            } catch (std::exception &e) {
                std::cout << "Error on line "<< lineNum <<": " << e.what() << '\n';
            }
        }


    file.close();
}
