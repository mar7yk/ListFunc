//
// Created by Marty Kostov on 23.07.22.
//

#include "ReadFunction.hpp"

IExpression *ReadFunction::get(const std::vector<IExpression *> &args) {
    double num;
    std::cin >> num;

    IExpression *result = new NumberExpression(num);
    MemoryManager::AddTempExpression(result);
    return result;
}