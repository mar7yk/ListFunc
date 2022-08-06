//
// Created by Marty Kostov on 23.07.22.
//

#include "WriteFunction.hpp"

ExecutableExpression *WriteFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    std::cout << a->execute() << '\n';

    auto *result = new NumberExpression(0);
    MemoryManager::AddTempExpression(result);
    return result;
}