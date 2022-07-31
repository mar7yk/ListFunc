//
// Created by Marty Kostov on 23.07.22.
//

#include "IfFunction.hpp"

ExecutableExpression *IfFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);
    IExpression *b = args[1];
    IExpression *c = args[2];

    auto *numberA = dynamic_cast<NumberExpression *>(a);

    if (!numberA) {
        throw std::invalid_argument("Not valid argument");
    }

    if(bool(numberA->getNumber())) {
        return b->get(customArgs);
    } else {
        return c->get(customArgs);
    }
}