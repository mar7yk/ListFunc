//
// Created by Marty Kostov on 24.07.22.
//

#include "FunctionProxy.hpp"

IFunction *FunctionProxy::getFunc() {
    IFunction *function = functionRegister->get(name, argsNum);
    if (!function) {
        throw std::invalid_argument("Unknown function '" + name + "'!");
    }
    return function;
}

FunctionProxy::FunctionProxy(FunctionRegister *functionRegister, const std::string &name) : functionRegister(
        functionRegister), name(name) {}

void FunctionProxy::addArgsNum(const size_t &argsCount) {
    argsNum = argsCount;
}

ExecutableExpression *FunctionProxy::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IFunction *func = getFunc();
    return func->get(args, customArgs);
}
