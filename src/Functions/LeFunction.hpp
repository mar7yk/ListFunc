//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_LEFUNCTION_HPP
#define LISTFUNC_LEFUNCTION_HPP


#include "TwoNumberFunction.hpp"

class LeFunction : public TwoNumberFunction {
    NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) override;
};


#endif //LISTFUNC_LEFUNCTION_HPP
