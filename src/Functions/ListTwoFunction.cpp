//
// Created by Marty Kostov on 23.07.22.
//

#include "ListTwoFunction.hpp"

ExecutableExpression *ListTwoFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    IExecutable *a = args[0]->get(customArgs);
    IExecutable *b = args[1]->get(customArgs);
    IExecutable *c = args[2]->get(customArgs);

    auto *numberA = dynamic_cast<NumberExpression *>(a);
    auto *numberB = dynamic_cast<NumberExpression *>(b);
    auto *numberC = dynamic_cast<NumberExpression *>(c);
    if (!numberA || !numberB || !numberC || !numberC->isUnsigned()) {
        throw std::invalid_argument("Not valid argument");
    }

    double itemValue = numberA->getNumber();
    double interval = numberB->getNumber();

    std::vector<NumberExpression *> items(numberC->getUnsigned());
    for (size_t i = 0; i < items.size(); ++i) {
        items[i] = new NumberExpression(itemValue);
        itemValue += interval;
    }

    auto list = new ListExpression(nullptr, nullptr);
    for (size_t i = items.size(); i > 0; --i) {
        list = new ListExpression(items[i-1], list);
    }

    MemoryManager::AddTempExpression(list);
    return list;
}
