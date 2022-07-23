//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_SQRTFUNCTION_HPP
#define LISTFUNC_SQRTFUNCTION_HPP

#include "PredefineFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class SqrtFunction : public PredefineFunction {
    ParameterExpression parm0 = ParameterExpression(0);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_SQRTFUNCTION_HPP