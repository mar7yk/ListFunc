//
// Created by Marty Kostov on 23.07.22.
//

#include "IfFunction.hpp"

IExpression *IfFunction::get(const std::vector<IExpression *> &args) {

    IExpression *a = parm0.get(args);
    IExpression *b = parm1.get(args);
    IExpression *c = parm2.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);

    if(bool(numberA->getNumber())) {
        return b;
    } else {
        return c;
    }
}