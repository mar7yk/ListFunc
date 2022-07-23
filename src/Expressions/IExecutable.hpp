//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_IEXECUTABLE_HPP
#define LISTFUNC_IEXECUTABLE_HPP

#include <string>

class IExecutable {
public:
    virtual std::string execute() = 0;

    virtual ~IExecutable() = default;
};


#endif //LISTFUNC_IEXECUTABLE_HPP
