//
// Created by Marty Kostov on 22.07.22.
//

#include "CustomFunction.hpp"

CustomFunction::CustomFunction(IExpression *expression) : expression(expression) {}

CustomFunction::~CustomFunction() {
    delete expression;
}

ExecutableExpression *CustomFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    std::vector<ExecutableExpression *> newCustomArgs;
    for (int i = 0; i < args.size(); ++i) {
        ExecutableExpression *CustomArg = args[i]->get(customArgs);
        newCustomArgs.push_back(CustomArg);
    }
    return expression->get(newCustomArgs);
}

size_t CustomFunction::getParmCount() {
    return expression->getParmCount();
}
