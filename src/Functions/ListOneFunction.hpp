//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_LISTONEFUNCTION_HPP
#define LISTFUNC_LISTONEFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"
#include "../Expressions/InfinityListExpression.hpp"

class ListOneFunction : public IFunction {
    ParameterExpression parm0 = ParameterExpression(0);
    ParameterExpression parm1 = ParameterExpression(1);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_LISTONEFUNCTION_HPP
