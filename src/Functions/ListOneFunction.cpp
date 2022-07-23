//
// Created by Marty Kostov on 22.07.22.
//

#include "ListOneFunction.hpp"

IExpression *ListOneFunction::get(const std::vector<IExpression *> &args) {
    delete forDelete;

    IExpression *a = parm0.get(args);
    IExpression *b = parm1.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    if (!numberA || !numberB) {
        throw std::invalid_argument("Not valid argument");
    }

    forDelete = new InfinityListExpression(numberA->getNumber(), numberB->getNumber());

    return forDelete;
}
