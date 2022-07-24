//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_CONCATFUNCTION_HPP
#define LISTFUNC_CONCATFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/ListExpression.hpp"

class ConcatFunction : public IFunction {
    ParameterExpression parm0 = ParameterExpression(0);
    ParameterExpression parm1 = ParameterExpression(1);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_CONCATFUNCTION_HPP
