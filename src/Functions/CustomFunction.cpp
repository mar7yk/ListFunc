//
// Created by Marty Kostov on 22.07.22.
//

#include "CustomFunction.hpp"

CustomFunction::CustomFunction(IExpression *expression) : expression(expression) {}

CustomFunction::~CustomFunction() {
    delete expression;
}

IExpression *CustomFunction::get(const std::vector<IExpression *> &args) {
    return expression->get(args);
}

size_t CustomFunction::getParmCount() {
    return expression->getParmCount();
}
