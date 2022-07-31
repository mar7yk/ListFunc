//
// Created by Marty Kostov on 31.07.22.
//

#ifndef LISTFUNC_GETLISTFUNCTION_HPP
#define LISTFUNC_GETLISTFUNCTION_HPP

#include <vector>

#include "IFunction.hpp"
#include "../Expressions/ListExpression.hpp"

class GetListFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_GETLISTFUNCTION_HPP
