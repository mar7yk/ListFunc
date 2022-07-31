//
// Created by Marty Kostov on 23.07.22.
//

#include "ConcatFunction.hpp"

ExecutableExpression *ConcatFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);
    IExecutable *b = args[1]->get(customArgs);

    auto *listA = dynamic_cast<ListExpression *>(a);
    auto *listB = dynamic_cast<ListExpression *>(b);
    if (!listA || !listB) {
        throw std::invalid_argument("Not valid argument");
    }

    ListExpression *result = ListExpression::concat(listA, listB);
    MemoryManager::AddTempExpression(result);
    return result;
}