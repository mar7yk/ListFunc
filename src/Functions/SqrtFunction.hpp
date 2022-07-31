//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_SQRTFUNCTION_HPP
#define LISTFUNC_SQRTFUNCTION_HPP

#include <cmath>

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class SqrtFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_SQRTFUNCTION_HPP
