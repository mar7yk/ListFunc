//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_LISTTWOFUNCTION_HPP
#define LISTFUNC_LISTTWOFUNCTION_HPP

#include "PredefineFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"
#include "../Expressions/ListExpression.hpp"

class ListTwoFunction : public PredefineFunction {
    ParameterExpression parm0 = ParameterExpression(0);
    ParameterExpression parm1 = ParameterExpression(1);
    ParameterExpression parm2 = ParameterExpression(2);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_LISTTWOFUNCTION_HPP