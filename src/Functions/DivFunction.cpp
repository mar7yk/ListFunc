//
// Created by Marty Kostov on 23.07.22.
//

#include "DivFunction.hpp"

NumberExpression *DivFunction::getResult(NumberExpression *numberA, NumberExpression *numberB) {
    if (numberB->getNumber() == 0) {
        throw std::invalid_argument("Divide by zero!");
    }
    return new NumberExpression(numberA->getNumber() / numberB->getNumber());
}