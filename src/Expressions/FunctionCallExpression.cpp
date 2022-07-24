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
}

std::string FunctionCallExpression::getValue(const std::vector<IExpression*> &_args) {
    return execute();
}

IExpression *FunctionCallExpression::get(const std::vector<IExpression *> &_args) {
    std::vector<IExpression *> tempArgs;
    for (int i = 0; i < args.size(); ++i) {
        tempArgs.push_back(args[i]->get(_args));
    }
    return func->get(tempArgs);
}

IExpression *FunctionCallExpression::get() {
    return func->get(args);
}

IExpression *FunctionCallExpression::getComparable() {
    IExpression* result = get();
    IExpression* comparable = result->getComparable();
    return comparable;
}

std::string FunctionCallExpression::execute() {
    IExpression* result = get();
    std::string value = result->getValue(args);

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

