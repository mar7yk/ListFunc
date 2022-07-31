//
// Created by Marty Kostov on 22.07.22.
//

#include "TailFunction.hpp"

ExecutableExpression *TailFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);

    auto *listA = dynamic_cast<ListExpression *>(a);
    if (!listA) {
        throw std::invalid_argument("Not valid argument");
    }

    return listA->getTail();
}
