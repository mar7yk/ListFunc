//
// Created by Marty Kostov on 22.07.22.
//

#include "HeadFunction.hpp"

IExpression *HeadFunction::get(const std::vector<IExpression *> &args) {
    IExpression *a = parm0.get(args);

    auto *listA = dynamic_cast<ListExpression *>(a);
    if (!listA) {
        throw std::invalid_argument("Not valid argument");
    }

    return listA->getHead();
}
