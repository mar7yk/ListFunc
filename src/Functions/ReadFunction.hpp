//
// Created by Marty Kostov on 23.07.22.
//

#ifndef LISTFUNC_READFUNCTION_HPP
#define LISTFUNC_READFUNCTION_HPP

#include <iostream>

#include "IFunction.hpp"
#include "../Expressions/NumberExpression.hpp"

class ReadFunction : public IFunction {
public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_READFUNCTION_HPP
