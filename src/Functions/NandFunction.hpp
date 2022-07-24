//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_NANDFUNCTION_HPP
#define LISTFUNC_NANDFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"

class NandFunction : public IFunction {
    ParameterExpression parm0 = ParameterExpression(0);
    ParameterExpression parm1 = ParameterExpression(1);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_NANDFUNCTION_HPP
