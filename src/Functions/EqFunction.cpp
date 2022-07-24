//
// Created by Marty Kostov on 22.07.22.
//

#include "EqFunction.hpp"

IExpression *EqFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);
    IExpression *b = parm1.get(args);

    IExpression *comparableA = a->getComparable();
    IExpression *comparableB = b->getComparable();

    if (!comparableA || !comparableB) {
        throw std::invalid_argument("Not valid argument");
    }


    if (comparableA->getValue(args) == comparableB->getValue(args)) {
        IExpression *result = new NumberExpression(1);
        MemoryManager::AddTempExpression(result);
        return result;
    } else {
        IExpression *result = new NumberExpression(0);
        MemoryManager::AddTempExpression(result);
        return result;
    }
}