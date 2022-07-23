//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_MULFUNCTION_HPP
#define LISTFUNC_MULFUNCTION_HPP

#include "TwoNumberFunction.hpp"

class MulFunction : public TwoNumberFunction {
    NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) override;
};


#endif //LISTFUNC_MULFUNCTION_HPP
