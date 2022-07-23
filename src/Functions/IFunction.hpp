//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_IFUNCTION_HPP
#define LISTFUNC_IFUNCTION_HPP

#include "../Expressions/IExpression.hpp"

class IFunction {

public:
    virtual IExpression* get(const std::vector<IExpression*> &args) = 0;

    virtual ~IFunction() = default;
};

#endif //LISTFUNC_IFUNCTION_HPP
