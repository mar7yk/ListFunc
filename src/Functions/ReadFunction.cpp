//
// Created by Marty Kostov on 23.07.22.
//

#include "ReadFunction.hpp"

IExpression *ReadFunction::get(const std::vector<IExpression *> &args) {
    delete forDelete;

    double num;
    std::cin >> num;

    forDelete = new NumberExpression(num);
    return forDelete;
}