//
// Created by Marty Kostov on 22.07.22.
//

#include "NandFunction.hpp"

IExpression *NandFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    if (!numberA) {
        throw std::invalid_argument(a->getValue(args) + "is not a number!");
    }

    if ( !(bool)numberA->getNumber() ) {
        IExpression *result = new NumberExpression(1);
        MemoryManager::AddTempExpression(result);
        return result;
    }

    IExpression *b = parm1.get(args);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    if (!numberB) {
        throw std::invalid_argument(b->getValue(args) + "is not a number!");
    }


    if ( !(bool)numberB->getNumber() ) {
        IExpression *result = new NumberExpression(1);
        MemoryManager::AddTempExpression(result);
        return result;

    } else {
        IExpression *result = new NumberExpression(0);
        MemoryManager::AddTempExpression(result);
        return result;
    }
}
