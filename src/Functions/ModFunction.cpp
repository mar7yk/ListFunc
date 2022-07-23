//
// Created by Marty Kostov on 23.07.22.
//

#include "ModFunction.hpp"

NumberExpression *ModFunction::getResult(NumberExpression *numberA, NumberExpression *numberB) {
    if (!numberA->isInt() || !numberB->isInt()) {
        throw std::invalid_argument("Not valid argument");
    }
    if (numberB->getNumber() == 0) {
        throw std::invalid_argument("Divide by zero!");
    }
    return new NumberExpression(numberA->getInt() % numberB->getInt());
}