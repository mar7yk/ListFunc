//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_NUMBEREXPRESSION_HPP
#define LISTFUNC_NUMBEREXPRESSION_HPP


#include "IExpression.hpp"
#include "IExecutable.hpp"

class NumberExpression : public IExpression, public IExecutable {
    double value;

public:
    explicit NumberExpression(double value);

    double getNumber() const;
    size_t getUnsigned() const;
    int getInt() const;
    bool isInt() const;
    bool isUnsigned() const;

    std::string getValue(const std::vector<IExpression*> &args) override;
    IExpression *get(const std::vector<IExpression *> &args) override;
    IExpression *getComparable() override;

    size_t getParmCount() override;

    std::string execute() override;
};



#endif //LISTFUNC_NUMBEREXPRESSION_HPP
