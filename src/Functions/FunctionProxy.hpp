//
// Created by Marty Kostov on 24.07.22.
//

#ifndef LISTFUNC_FUNCTIONPROXY_HPP
#define LISTFUNC_FUNCTIONPROXY_HPP

#include "IFunction.hpp"
#include "../FunctionRegister.hpp"

class FunctionProxy : public IFunction {
    FunctionRegister * functionRegister;
    std::string name;
    size_t argsNum = 0;

    IFunction *function = nullptr;

    IFunction *getFunc();

public:
    FunctionProxy() = delete;
    FunctionProxy(FunctionRegister *functionRegister, const std::string &name);
    ~FunctionProxy() override;

    void addArgsNum(const size_t &argsCount);

private:
    IExpression *get(const std::vector<IExpression *> &args) override;

};


#endif //LISTFUNC_FUNCTIONPROXY_HPP
