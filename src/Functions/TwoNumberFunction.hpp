//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_TWONUMBERFUNCTION_HPP
#define LISTFUNC_TWONUMBERFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class TwoNumberFunction : public IFunction {
    virtual NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) = 0;

public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_TWONUMBERFUNCTION_HPP
