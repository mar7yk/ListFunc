//
// Created by Marty Kostov on 23.07.22.
//

#include "ReadFunction.hpp"

ExecutableExpression *ReadFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    double num;
    std::cin >> num;

    auto *result = new NumberExpression(num);
    MemoryManager::AddTempExpression(result);
    return result;
}