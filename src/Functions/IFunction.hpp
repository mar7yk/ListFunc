//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_IFUNCTION_HPP
#define LISTFUNC_IFUNCTION_HPP

#include "../Expressions/IExecutable.hpp"
#include "../MemoryManager.hpp"

class IFunction {

public:
    virtual ExecutableExpression* get(const std::vector<IExpression*> &args, const std::vector<ExecutableExpression*> &customArgs) = 0;

    virtual ~IFunction() = default;
};

#endif //LISTFUNC_IFUNCTION_HPP
