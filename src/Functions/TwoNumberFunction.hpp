//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_TWONUMBERFUNCTION_HPP
#define LISTFUNC_TWONUMBERFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class TwoNumberFunction : public IFunction {
    ParameterExpression parm0 = ParameterExpression(0);
    ParameterExpression parm1 = ParameterExpression(1);

    virtual NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) = 0;

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_TWONUMBERFUNCTION_HPP
