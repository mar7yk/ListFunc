//
// Created by Marty Kostov on 22.07.22.
//

#include "LengthFunction.hpp"

IExpression *LengthFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);

    auto *listA = dynamic_cast<ListExpression *>(a);
    if (!listA) {
        auto *numberA = dynamic_cast<NumberExpression *>(a);
        if (!numberA) {
            throw std::invalid_argument(a->getValue(args) + "is not a number!");
        }

        IExpression *result = new NumberExpression(-1);
        MemoryManager::AddTempExpression(result);
        return result;
    }

    IExpression *result = new NumberExpression(listA->getLength());
    MemoryManager::AddTempExpression(result);
    return result;
}