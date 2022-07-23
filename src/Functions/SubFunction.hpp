//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_SUBFUNCTION_HPP
#define LISTFUNC_SUBFUNCTION_HPP

#include "TwoNumberFunction.hpp"

class SubFunction : public TwoNumberFunction {
    NumberExpression *getResult(NumberExpression *numberA, NumberExpression *numberB) override;
};


#endif //LISTFUNC_SUBFUNCTION_HPP
