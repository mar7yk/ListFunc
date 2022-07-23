//
// Created by Marty Kostov on 22.07.22.
//

#ifndef LISTFUNC_IEXPRESSION_HPP
#define LISTFUNC_IEXPRESSION_HPP

#include <vector>
#include <string>

class IExpression {
public:
    virtual std::string getValue(const std::vector<IExpression*> &args) = 0;
    virtual IExpression* get(const std::vector<IExpression*> &args) = 0;
    virtual IExpression* getComparable() = 0;
    virtual size_t getParmCount() = 0;

    virtual ~IExpression() = default;
};


#endif //LISTFUNC_IEXPRESSION_HPP
