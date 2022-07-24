//
// Created by Marty Kostov on 22.07.22.
//

#include "ListZeroFunction.hpp"

IExpression *ListZeroFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    if (!numberA) {
        throw std::invalid_argument("Not valid argument");
    }

    IExpression *result = new InfinityListExpression(numberA->getNumber(), 1);
    MemoryManager::AddTempExpression(result);
    return result;
}
