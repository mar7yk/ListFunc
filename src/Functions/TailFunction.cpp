//
// Created by Marty Kostov on 22.07.22.
//

#include "TailFunction.hpp"

IExpression *TailFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);

    auto *listA = dynamic_cast<ListExpression *>(a);
    if (!listA) {
        throw std::invalid_argument("Not valid argument");
    }

    return listA->getTail();
}
