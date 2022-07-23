//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_FUNCTIONCALLEXPRESSION_HPP
#define LISTFUNC_FUNCTIONCALLEXPRESSION_HPP

#include "../Functions/IFunction.hpp"
#include "IExecutable.hpp"

class FunctionCallExpression : public IExpression, public IExecutable {
    IFunction* func;
    std::vector<IExpression*> args;

    IExpression *get();
public:
    FunctionCallExpression(IFunction *func, const std::vector<IExpression *> &args);

    ~FunctionCallExpression() override;

    void addArgument(IExpression* arg);

    std::string getValue(const std::vector<IExpression*> &_args) override;
    IExpression *get(const std::vector<IExpression *> &_args) override;
    IExpression *getComparable() override;
    size_t getParmCount() override;

    std::string execute() override;

};



#endif //LISTFUNC_FUNCTIONCALLEXPRESSION_HPP
