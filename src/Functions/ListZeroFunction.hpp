//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_LISTZEROFUNCTION_HPP
#define LISTFUNC_LISTZEROFUNCTION_HPP

#include "PredefineFunction.hpp"
#include "../Expressions/ParameterExpression.hpp"
#include "../Expressions/NumberExpression.hpp"
#include "../Expressions/InfinityListExpression.hpp"

class ListZeroFunction : public PredefineFunction {
    ParameterExpression parm0 = ParameterExpression(0);

public:
    IExpression *get(const std::vector<IExpression *> &args) override;
};


#endif //LISTFUNC_LISTZEROFUNCTION_HPP
