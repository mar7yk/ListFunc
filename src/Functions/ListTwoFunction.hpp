//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_LISTTWOFUNCTION_HPP
#define LISTFUNC_LISTTWOFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"
#include "../Expressions/ListExpression.hpp"

class ListTwoFunction : public IFunction {
public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};


#endif //LISTFUNC_LISTTWOFUNCTION_HPP
