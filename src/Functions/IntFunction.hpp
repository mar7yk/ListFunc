//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_INTFUNCTION_HPP
#define LISTFUNC_INTFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class IntFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_INTFUNCTION_HPP
