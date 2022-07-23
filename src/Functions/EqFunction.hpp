//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_EQFUNCTION_HPP
#define LISTFUNC_EQFUNCTION_HPP

#include "PredefineFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class EqFunction : public PredefineFunction {
    ParameterExpression parm0 = ParameterExpression(0);
    ParameterExpression parm1 = ParameterExpression(1);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};



#endif //LISTFUNC_EQFUNCTION_HPP
