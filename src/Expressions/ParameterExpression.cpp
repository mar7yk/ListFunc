//
// Created by Marty Kostov on 22.07.22.
//

#include "ParameterExpression.hpp"

ParameterExpression::ParameterExpression(size_t index) : index(index) {}

std::string ParameterExpression::getValue(const std::vector<IExpression*> &args) {
    return args[index]->getValue(args);
}

ExecutableExpression *ParameterExpression::get(const std::vector<ExecutableExpression*> &customArgs) {
    return customArgs[index];
}

size_t ParameterExpression::getParmCount() {
    return index + 1;
}
