//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_INFINITYLISTEXPRESSION_HPP
#define LISTFUNC_INFINITYLISTEXPRESSION_HPP

#include "ExecutableExpression.hpp"

class InfinityListExpression : public ExecutableExpression {
    double start;
    double interval;

public:
    InfinityListExpression(double start, double interval);

    ExecutableExpression *get(const std::vector<ExecutableExpression*> &customArgs) override;
    IExecutable *getComparable() override;
    size_t getParmCount() override;

    std::string execute() override;
};



#endif //LISTFUNC_INFINITYLISTEXPRESSION_HPP
