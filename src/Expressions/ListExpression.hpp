//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_LISTEXPRESSION_HPP
#define LISTFUNC_LISTEXPRESSION_HPP

#include "IExpression.hpp"
#include "IExecutable.hpp"

class ListExpression : public IExpression {
protected:
    IExpression* head;
    ListExpression* tail;
//    std::vector<IExpression*> values;

public:
    ListExpression(IExpression *head, ListExpression *tail);

    ~ListExpression() override;

    std::string getValues(const std::vector<IExpression*> &args);
    int getLength();
    IExpression *getHead();
    ListExpression *getTail();

    static ListExpression *concat(ListExpression * left, ListExpression * right);

    std::string getValue(const std::vector<IExpression*> &args) override;
    IExpression *get(const std::vector<IExpression *> &args) override;
    IExpression *getComparable() override;
    size_t getParmCount() override;
};

class ExecutableListExpression : public ListExpression, public IExecutable {
public:
    ExecutableListExpression(IExpression *head, ListExpression *tail);

    std::string executeValues();
    std::string execute() override;

    size_t getParmCount() override;
};


class ListViewExpression : public ListExpression {
public:
    ListViewExpression(IExpression *head, ListExpression *tail);

    ~ListViewExpression() override;
};



#endif //LISTFUNC_LISTEXPRESSION_HPP
