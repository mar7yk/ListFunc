//
// Created by Marty Kostov on 22.07.22.
//

#include "NumberExpression.hpp"

NumberExpression::NumberExpression(double value) : value(value) {}

ExecutableExpression *NumberExpression::get(const std::vector<ExecutableExpression*> &customArgs) {
    return this;
}

IExecutable *NumberExpression::getComparable() {
    return this;
}

bool NumberExpression::isInt() const {
    return abs(value - long(value)) < 0.000001;
}

std::string NumberExpression::execute() {
    if (isInt()) {
        return std::to_string(long(value));
    }
    return std::to_string(value);
}

double NumberExpression::getNumber() const {
    return value;
}

int NumberExpression::getInt() const {
    return int(value);
}

bool NumberExpression::isUnsigned() const {
    return value - int(value) < 0.000001 && value > 0;
}

size_t NumberExpression::getUnsigned() const {
    return size_t(value);
}

size_t NumberExpression::getParmCount() {
    return 0;
}
