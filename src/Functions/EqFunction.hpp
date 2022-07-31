//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_EQFUNCTION_HPP
#define LISTFUNC_EQFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class EqFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};



#endif //LISTFUNC_EQFUNCTION_HPP
