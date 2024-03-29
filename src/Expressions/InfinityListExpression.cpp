//
// Created by Marty Kostov on 22.07.22.
//

#include "InfinityListExpression.hpp"
#include "NumberExpression.hpp"

InfinityListExpression::InfinityListExpression(double start, double interval) : start(start), interval(interval) {}

ExecutableExpression *InfinityListExpression::get(const std::vector<ExecutableExpression*> &customArgs) {
    return this;
}

IExecutable *InfinityListExpression::getComparable() {
    return this;
}

std::string InfinityListExpression::execute() {
    std::string result = "[";

    double currValue = start;
    for (int i = 0; i < 8; ++i) {
        result += NumberExpression(currValue).execute();
        result += " ";
        currValue = currValue + interval;
    }

    result += "...]";

    return result;
}

size_t InfinityListExpression::getParmCount() {
    return 0;
}
