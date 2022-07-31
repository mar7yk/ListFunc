//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_CONCATFUNCTION_HPP
#define LISTFUNC_CONCATFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/ListExpression.hpp"

class ConcatFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_CONCATFUNCTION_HPP
