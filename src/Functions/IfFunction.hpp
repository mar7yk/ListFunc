//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_IFFUNCTION_HPP
#define LISTFUNC_IFFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class IfFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_IFFUNCTION_HPP
