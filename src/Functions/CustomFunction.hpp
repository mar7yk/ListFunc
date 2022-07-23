//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_CUSTOMFUNCTION_HPP
#define LISTFUNC_CUSTOMFUNCTION_HPP

#include "IFunction.hpp"

class CustomFunction : public IFunction {
    IExpression* expression;

public:
    explicit CustomFunction(IExpression *expression);
    ~CustomFunction() override;

    IExpression *get(const std::vector<IExpression *> &args) override;

    size_t getParmCount();
};



#endif //LISTFUNC_CUSTOMFUNCTION_HPP
