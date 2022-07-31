//
// Created by Marty Kostov on 22.07.22.
//

#include "NandFunction.hpp"

ExecutableExpression *NandFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    if (!numberA) {
        throw std::invalid_argument(a->execute() + "is not a number!");
    }

    if ( !(bool)numberA->getNumber() ) {
        auto *result = new NumberExpression(1);
        MemoryManager::AddTempExpression(result);
        return result;
    }

    IExecutable *b = args[1]->get(customArgs);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    if (!numberB) {
        throw std::invalid_argument(b->execute() + "is not a number!");
    }


    if ( !(bool)numberB->getNumber() ) {
        auto *result = new NumberExpression(1);
        MemoryManager::AddTempExpression(result);
        return result;

    } else {
        auto *result = new NumberExpression(0);
        MemoryManager::AddTempExpression(result);
        return result;
    }
}
