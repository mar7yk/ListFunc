//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_HEADFUNCTION_HPP
#define LISTFUNC_HEADFUNCTION_HPP

#include "PredefineFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/ListExpression.hpp"

class HeadFunction : public PredefineFunction {
    ParameterExpression parm0 = ParameterExpression(0);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_HEADFUNCTION_HPP
