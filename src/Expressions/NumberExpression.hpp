//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_NUMBEREXPRESSION_HPP
#define LISTFUNC_NUMBEREXPRESSION_HPP

#include "ExecutableExpression.hpp"

class NumberExpression : public ExecutableExpression {
    double value;

public:
    explicit NumberExpression(double value);

    double getNumber() const;
    size_t getUnsigned() const;
    int getInt() const;
    bool isInt() const;
    bool isUnsigned() const;

    ExecutableExpression *get(const std::vector<ExecutableExpression*> &customArgs) override;
    IExecutable *getComparable() override;

    size_t getParmCount() override;

    std::string execute() override;
};



#endif //LISTFUNC_NUMBEREXPRESSION_HPP
