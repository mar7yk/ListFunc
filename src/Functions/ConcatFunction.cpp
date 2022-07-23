//
// Created by Marty Kostov on 23.07.22.
//

#include "ConcatFunction.hpp"

IExpression *ConcatFunction::get(const std::vector<IExpression *> &args) {
    delete forDelete;

    IExpression *a = parm0.get(args);
    IExpression *b = parm1.get(args);

    auto *listA = dynamic_cast<ListExpression *>(a);
    auto *listB = dynamic_cast<ListExpression *>(b);
    if (!listA || !listB) {
        throw std::invalid_argument("Not valid argument");
    }

    forDelete = ListExpression::concat(listA, listB);
    return forDelete;
}