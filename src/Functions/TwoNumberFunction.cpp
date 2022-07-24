//
// Created by Marty Kostov on 23.07.22.
//

#include "TwoNumberFunction.hpp"

IExpression *TwoNumberFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);
    IExpression *b = parm1.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    auto *numberB = dynamic_cast<NumberExpression *>(b);

    if (!numberA || !numberB) {
        throw std::invalid_argument("Not valid argument");
    }

    IExpression *result = getResult(numberA, numberB);
    MemoryManager::AddTempExpression(result);
    return result;
}