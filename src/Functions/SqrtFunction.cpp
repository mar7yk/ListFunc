//
// Created by Marty Kostov on 23.07.22.
//

#include "SqrtFunction.hpp"

IExpression *SqrtFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);

    if (!numberA ) {
        throw std::invalid_argument("Not valid argument");
    }

    IExpression *result = new NumberExpression(numberA->getNumber() * numberA->getNumber());
    MemoryManager::AddTempExpression(result);
    return result;
}