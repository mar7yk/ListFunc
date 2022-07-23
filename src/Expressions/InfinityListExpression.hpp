//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_INFINITYLISTEXPRESSION_HPP
#define LISTFUNC_INFINITYLISTEXPRESSION_HPP

#include "IExpression.hpp"
#include "IExecutable.hpp"

class InfinityListExpression : public IExpression, public IExecutable {
    double start;
    double interval;

public:
    InfinityListExpression(double start, double interval);

    std::string getValue(const std::vector<IExpression*> &args) override;
    IExpression *get(const std::vector<IExpression *> &args) override;
    IExpression *getComparable() override;
    size_t getParmCount() override;

    std::string execute() override;
};



#endif //LISTFUNC_INFINITYLISTEXPRESSION_HPP
