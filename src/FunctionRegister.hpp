//
// Created by Marty Kostov on 19.07.22.
//

#ifndef LISTFUNC_FUNCTIONREGISTER_HPP
#define LISTFUNC_FUNCTIONREGISTER_HPP

#include <unordered_map>

#include "Functions/EqFunction.hpp"
#include "Functions/LeFunction.hpp"
#include "Functions/NandFunction.hpp"
#include "Functions/LengthFunction.hpp"
#include "Functions/HeadFunction.hpp"
#include "Functions/TailFunction.hpp"
#include "Functions/ListZeroFunction.hpp"
#include "Functions/ListOneFunction.hpp"
#include "Functions/ListTwoFunction.hpp"
#include "Functions/ConcatFunction.hpp"
#include "Functions/IfFunction.hpp"
#include "Functions/ReadFunction.hpp"
#include "Functions/IntFunction.hpp"
#include "Functions/AddFunction.hpp"
#include "Functions/SubFunction.hpp"
#include "Functions/MulFunction.hpp"
#include "Functions/DivFunction.hpp"
#include "Functions/ModFunction.hpp"
#include "Functions/SqrtFunction.hpp"

class FunctionRegister {
    struct Node {
        std::vector<IFunction*> functions;
        std::unordered_map<char, Node*> children;

        Node* addNote(char symbol);
        bool addFunc(const size_t &agrsNum, IFunction *function);
        Node* getNote(char symbol);
        IFunction* getFunc(const size_t &agrsNum);

        ~Node();
    } rood;

public:
    FunctionRegister();

    bool add(const std::string &name, const size_t &argsNum, IFunction* function);
    IFunction* get(const std::string &name, const size_t &argsNum);
};


#endif //LISTFUNC_FUNCTIONREGISTER_HPP
