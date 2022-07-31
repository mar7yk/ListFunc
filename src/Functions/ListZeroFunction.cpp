//
// Created by Marty Kostov on 22.07.22.
//

#include "ListZeroFunction.hpp"

ExecutableExpression *ListZeroFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    if (!numberA) {
        throw std::invalid_argument("Not valid argument");
    }

    auto *result = new InfinityListExpression(numberA->getNumber(), 1);
    MemoryManager::AddTempExpression(result);
    return result;
}
