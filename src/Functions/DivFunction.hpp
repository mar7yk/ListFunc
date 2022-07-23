//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_DIVFUNCTION_HPP
#define LISTFUNC_DIVFUNCTION_HPP

#include "TwoNumberFunction.hpp"

class DivFunction : public TwoNumberFunction {
    NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) override;
};


#endif //LISTFUNC_DIVFUNCTION_HPP
