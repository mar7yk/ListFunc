//
// Created by Marty Kostov on 23.07.22.
//

#include "WriteFunction.hpp"

IExpression *WriteFunction::get(const std::vector<IExpression *> &args) {
    delete forDelete;
    IExpression *a = parm0.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    if (!numberA) {
        throw std::invalid_argument("Not valid argument");
    }

    std::cout << numberA->getNumber() << '\n';

    forDelete = new NumberExpression(0);

    return forDelete;
}