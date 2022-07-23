//
// Created by Marty Kostov on 23.07.22.
//

#include "MulFunction.hpp"

NumberExpression *MulFunction::getResult(NumberExpression *numberA, NumberExpression *numberB) {
    return new NumberExpression(numberA->getNumber() * numberB->getNumber());
}