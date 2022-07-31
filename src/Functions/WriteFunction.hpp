//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_WRITEFUNCTION_HPP
#define LISTFUNC_WRITEFUNCTION_HPP

#include <iostream>

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class WriteFunction : public IFunction {
    ParameterExpression parm0 = ParameterExpression(0);

public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_WRITEFUNCTION_HPP
