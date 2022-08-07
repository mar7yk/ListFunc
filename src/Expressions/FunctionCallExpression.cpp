//
// Created by Marty Kostov on 22.07.22.
//

#include "FunctionCallExpression.hpp"

FunctionCallExpression::FunctionCallExpression(IFunction *func, const std::vector<IExpression *> &args) : func(func),
                                                                                                          args(args) {}

FunctionCallExpression::~FunctionCallExpression() {
    for (int i = 0; i < args.size(); ++i) {
        delete args[i];
    }
    delete func;
}

ExecutableExpression *FunctionCallExpression::get(const std::vector<ExecutableExpression*> &customArgs) {
    std::vector<IExpression *> tempArgs;
    return func->get(args, customArgs);
}

IExecutable *FunctionCallExpression::get() {
    return func->get(args, {});
}

IExecutable *FunctionCallExpression::getComparable() {
    IExecutable* result = get();
    IExecutable* comparable = result->getComparable();
    return comparable;
}

std::string FunctionCallExpression::execute() {
    IExecutable* result = get();
    std::string value = result->execute();

    MemoryManager::CleanTempExpression();

    return value;
}

size_t FunctionCallExpression::getParmCount() {
    size_t parmCount = 0;
    for (int i = 0; i < args.size(); ++i) {
        parmCount = std::max(parmCount, args[i]->getParmCount());
    }
    return parmCount;
}

