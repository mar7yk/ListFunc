//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_TAILFUNCTION_HPP
#define LISTFUNC_TAILFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/ListExpression.hpp"

class TailFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_TAILFUNCTION_HPP
