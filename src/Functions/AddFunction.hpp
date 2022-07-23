//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_ADDFUNCTION_HPP
#define LISTFUNC_ADDFUNCTION_HPP

#include "TwoNumberFunction.hpp"

class AddFunction : public TwoNumberFunction {
    NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) override;
};


#endif //LISTFUNC_ADDFUNCTION_HPP
