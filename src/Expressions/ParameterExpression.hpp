//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_PARAMETEREXPRESSION_HPP
#define LISTFUNC_PARAMETEREXPRESSION_HPP

#include "IExpression.hpp"

class ParameterExpression : public IExpression {
    size_t index;

public:
    explicit ParameterExpression(size_t index);

    ExecutableExpression *get(const std::vector<ExecutableExpression*> &customArgs) override;
    size_t getParmCount() override;
};



#endif //LISTFUNC_PARAMETEREXPRESSION_HPP
