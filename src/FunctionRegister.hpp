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
#include "Functions/WriteFunction.hpp"
#include "Functions/IntFunction.hpp"
#include "Functions/AddFunction.hpp"
#include "Functions/SubFunction.hpp"
#include "Functions/MulFunction.hpp"
#include "Functions/DivFunction.hpp"
#include "Functions/ModFunction.hpp"
#include "Functions/SqrtFunction.hpp"


/// Store all functions known to the interpreter.
class FunctionRegister {
    struct Node {
        std::vector<IFunction*> functions;
        std::unordered_map<char, Node*> children;

        ///add node with key symbol to #children of current node if there is not
        ///@return pointer to node whit key symbol from #children
        Node* addNote(char symbol);

        ///add node function whit agrsNum arguments to the node
        ///@return true if override other function
        bool addFunc(const size_t &agrsNum, IFunction *function);

        ///@return pointer to node with key symbol to #children
        Node* getNote(char symbol);

        ///@return pointer to function with agrsNum arguments
        IFunction* getFunc(const size_t &agrsNum);

        ~Node();
    } rood;

public:
    FunctionRegister();

    ///add function with name and count of arguments
    ///@return true if override other function
    bool add(const std::string &name, const size_t &argsNum, IFunction* function);

    ///@return pointer to function with name and count of arguments
    IFunction* get(const std::string &name, const size_t &argsNum);
};


#endif //LISTFUNC_FUNCTIONREGISTER_HPP
