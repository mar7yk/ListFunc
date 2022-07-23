//
// Created by Marty Kostov on 23.07.22.
//

#include "ListTwoFunction.hpp"

IExpression *ListTwoFunction::get(const std::vector<IExpression *> &args) {
    delete forDelete;

    IExpression *a = parm0.get(args);
    IExpression *b = parm1.get(args);
    IExpression *c = parm2.get(args);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    auto *numberC = dynamic_cast<NumberExpression *>(c);
    if (!numberA || !numberB || !numberC || !numberC->isUnsigned()) {
        throw std::invalid_argument("Not valid argument");
    }

    double itemValue = numberA->getNumber();
    double interval = numberB->getNumber();

    std::vector<IExpression *> items(numberC->getUnsigned());
    for (size_t i = 0; i < items.size(); ++i) {
        items[i] = new NumberExpression(itemValue);
        itemValue += interval;
    }

    auto list = new ListExpression(nullptr, nullptr);
    for (size_t i = items.size(); i > 0; --i) {
        list = new ListExpression(items[i-1], list);
    }

    forDelete = list;
    return forDelete;
}
