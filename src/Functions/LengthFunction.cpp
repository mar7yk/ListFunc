//
// Created by Marty Kostov on 22.07.22.
//

#include "LengthFunction.hpp"

IExpression *LengthFunction::get(const std::vector<IExpression *> &args) {
    delete forDelete;

    IExpression *a = parm0.get(args);

    auto *listA = dynamic_cast<ListExpression *>(a);
    if (!listA) {
        auto *numberA = dynamic_cast<NumberExpression *>(a);
        if (!numberA) {
            throw std::invalid_argument(a->getValue(args) + "is not a number!");
        }

        forDelete = new NumberExpression(-1);
        return forDelete;
    }

    forDelete = new NumberExpression(listA->getLength());
    return forDelete;
}