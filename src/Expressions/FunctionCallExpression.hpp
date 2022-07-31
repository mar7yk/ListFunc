//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_FUNCTIONCALLEXPRESSION_HPP
#define LISTFUNC_FUNCTIONCALLEXPRESSION_HPP

#include "../Functions/IFunction.hpp"
#include "ExecutableExpression.hpp"

class FunctionCallExpression : public ExecutableExpression {
    IFunction* func;
    std::vector<IExpression*> args;

    IExecutable *get();
public:
    FunctionCallExpression(IFunction *func, const std::vector<IExpression *> &args);
    ~FunctionCallExpression() override;

    std::string getValue(const std::vector<IExpression*> &_args) override;
    ExecutableExpression *get(const std::vector<ExecutableExpression*> &customArgs) override;
    IExecutable *getComparable() override;
    size_t getParmCount() override;

    std::string execute() override;

};



#endif //LISTFUNC_FUNCTIONCALLEXPRESSION_HPP
