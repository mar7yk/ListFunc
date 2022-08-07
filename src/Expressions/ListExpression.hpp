//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_LISTEXPRESSION_HPP
#define LISTFUNC_LISTEXPRESSION_HPP

#include "ExecutableExpression.hpp"

class ListExpression : public ExecutableExpression {
protected:
    ExecutableExpression* head;
    ListExpression* tail;

    std::string executeValues();
public:
    ListExpression(ExecutableExpression *head, ListExpression *tail);

    ~ListExpression() override;

    int getLength();
    ExecutableExpression *getHead();
    ListExpression *getTail();

    static ListExpression *concat(ListExpression * left, ListExpression * right);

    ExecutableExpression *get(const std::vector<ExecutableExpression*> &customArgs) override;
    IExecutable *getComparable() override;
    size_t getParmCount() override;

    std::string execute() override;
};


class ListViewExpression : public ListExpression {
public:
    ListViewExpression(ExecutableExpression *head, ListExpression *tail);

    ~ListViewExpression() override;
};



#endif //LISTFUNC_LISTEXPRESSION_HPP
