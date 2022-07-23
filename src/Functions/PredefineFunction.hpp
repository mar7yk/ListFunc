//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_PREDEFINEFUNCTION_HPP
#define LISTFUNC_PREDEFINEFUNCTION_HPP

#include "IFunction.hpp"

class PredefineFunction : public IFunction {
protected:
    IExpression* forDelete;
public:
    ~PredefineFunction() override;
};



#endif //LISTFUNC_PREDEFINEFUNCTION_HPP
