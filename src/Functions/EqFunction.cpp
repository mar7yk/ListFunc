//
// Created by Marty Kostov on 22.07.22.
//

#include "EqFunction.hpp"

ExecutableExpression *EqFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);
    IExecutable *b = args[1]->get(customArgs);

    IExecutable *comparableA = a->getComparable();
    IExecutable *comparableB = b->getComparable();

    if (!comparableA || !comparableB) {
        throw std::invalid_argument("Not valid argument");
    }


    if (comparableA->execute() == comparableB->execute()) {
        auto *result = new NumberExpression(1);
        MemoryManager::AddTempExpression(result);
        return result;
    } else {
        auto *result = new NumberExpression(0);
        MemoryManager::AddTempExpression(result);
        return result;
    }
}