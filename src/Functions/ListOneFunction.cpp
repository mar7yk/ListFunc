//
// Created by Marty Kostov on 22.07.22.
//

#include "ListOneFunction.hpp"

IExpression *ListOneFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);
    IExpression *b = parm1.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    if (!numberA || !numberB) {
        throw std::invalid_argument("Not valid argument");
    }

    IExpression *result = new InfinityListExpression(numberA->getNumber(), numberB->getNumber());
    MemoryManager::AddTempExpression(result);
    return result;
}
