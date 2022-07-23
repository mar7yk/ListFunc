//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_MODFUNCTION_HPP
#define LISTFUNC_MODFUNCTION_HPP

#include "TwoNumberFunction.hpp"

class ModFunction : public TwoNumberFunction {
    NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) override;
};


#endif //LISTFUNC_MODFUNCTION_HPP
