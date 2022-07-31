//
// Created by Marty Kostov on 23.07.22.
//

#include "IntFunction.hpp"

ExecutableExpression *IntFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    auto *numberA = dynamic_cast<NumberExpression *>(a);

    if (!numberA) {
        throw std::invalid_argument("Not valid argument");
    }

    auto *result = new NumberExpression(numberA->getInt());
    MemoryManager::AddTempExpression(result);
    return result;
}