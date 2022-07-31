//
// Created by Marty Kostov on 22.07.22.
//

#include "LengthFunction.hpp"

ExecutableExpression *LengthFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    auto *listA = dynamic_cast<ListExpression *>(a);
    if (!listA) {
        auto *numberA = dynamic_cast<NumberExpression *>(a);
        if (!numberA) {
            throw std::invalid_argument(a->execute() + "is not a number!");
        }

        auto *result = new NumberExpression(-1);
        MemoryManager::AddTempExpression(result);
        return result;
    }

    auto *result = new NumberExpression(listA->getLength());
    MemoryManager::AddTempExpression(result);
    return result;
}