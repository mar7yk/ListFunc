//
// Created by Marty Kostov on 22.07.22.
//

#include "LeFunction.hpp"

NumberExpression *LeFunction::getResult(NumberExpression *numberA, NumberExpression *numberB) {
    if (numberA->getNumber() < numberB->getNumber()) {
        return new NumberExpression(1);
    } else {
        return new NumberExpression(0);
    }
}
