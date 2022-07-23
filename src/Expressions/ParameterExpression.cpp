//
// Created by Marty Kostov on 22.07.22.
//

#include "ParameterExpression.hpp"

ParameterExpression::ParameterExpression(size_t index) : index(index) {}

std::string ParameterExpression::getValue(const std::vector<IExpression*> &args) {
    return args[index]->getValue(args);
}

IExpression *ParameterExpression::get(const std::vector<IExpression *> &args) {
    return args[index]->get(args);
}

IExpression *ParameterExpression::getComparable() {
    return nullptr;
}

size_t ParameterExpression::getParmCount() {
    return index + 1;
}
