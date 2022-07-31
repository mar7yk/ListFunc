//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_LENGTHFUNCTION_HPP
#define LISTFUNC_LENGTHFUNCTION_HPP

#include "IFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"
#include "../Expressions/ListExpression.hpp"

class LengthFunction : public IFunction {
    ParameterExpression parm0 = ParameterExpression(0);

    public:
    ExecutableExpression *get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) override;
};

#endif //LISTFUNC_LENGTHFUNCTION_HPP
