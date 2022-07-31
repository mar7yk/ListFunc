//
// Created by Marty Kostov on 23.07.22.
//

#include <cmath>
#include "SqrtFunction.hpp"

ExecutableExpression *SqrtFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    auto *numberA = dynamic_cast<NumberExpression *>(a);

    if (!numberA ) {
        throw std::invalid_argument("Not valid argument");
    }

    auto *result = new NumberExpression( sqrt(numberA->getNumber()) );
    MemoryManager::AddTempExpression(result);
    return result;
}