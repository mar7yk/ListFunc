//
// Created by Marty Kostov on 22.07.22.
//

#include "ListOneFunction.hpp"

ExecutableExpression *ListOneFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);
    IExecutable *b = args[1]->get(customArgs);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    if (!numberA || !numberB) {
        throw std::invalid_argument("Not valid argument");
    }

    auto *result = new InfinityListExpression(numberA->getNumber(), numberB->getNumber());
    MemoryManager::AddTempExpression(result);
    return result;
}
