//
// Created by Marty Kostov on 22.07.22.
//

#include "NandFunction.hpp"

IExpression *NandFunction::get(const std::vector<IExpression *> &args) {
    delete forDelete;

    IExpression *a = parm0.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    if (!numberA) {
        throw std::invalid_argument(a->getValue(args) + "is not a number!");
    }

    if ( !(bool)numberA->getNumber() ) {
        forDelete = new NumberExpression(1);
        return forDelete;
    }

    IExpression *b = parm1.get(args);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    if (!numberB) {
        throw std::invalid_argument(b->getValue(args) + "is not a number!");
    }


    if ( !(bool)numberB->getNumber() ) {
        forDelete = new NumberExpression(1);
        return forDelete;
    } else {
        forDelete = new NumberExpression(0);
        return forDelete;
    }
}
