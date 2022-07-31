//
// Created by Marty Kostov on 23.07.22.
//

#include "WriteFunction.hpp"

ExecutableExpression *WriteFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    if (!numberA) {
        throw std::invalid_argument("Not valid argument");
    }

    std::cout << numberA->getNumber() << '\n';

    auto *result = new NumberExpression(0);
    MemoryManager::AddTempExpression(result);
    return result;
}