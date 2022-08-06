//
// Created by Marty Kostov on 19.07.22.
//

#include "FunctionRegister.hpp"

FunctionRegister::Node *FunctionRegister::Node::addNote(char symbol) {
    if(children[symbol] == nullptr) {
        children[symbol] = new Node();
    }
    return children[symbol];
}

bool FunctionRegister::Node::addFunc(const size_t &agrsNum, IFunction *function) {

    if (functions.size() < agrsNum + 1) {
        functions.resize(agrsNum + 1);
    }

    if(functions[agrsNum] == nullptr) {
        functions[agrsNum] = function;
        return false;

    } else {
        delete functions[agrsNum];
        functions[agrsNum] = function;
        return true;
    }
}

FunctionRegister::Node *FunctionRegister::Node::getNote(char symbol) {
    if(children.find(symbol) == this->children.end()) {
        return nullptr;
    }
    return children[symbol];
}

FunctionRegister::Node::~Node() {
    for (int i = 0; i < functions.size(); ++i) {
        delete functions[i];
    }
    for (std::unordered_map<char, Node*>::const_iterator iter = children.begin(); iter != children.end(); ++iter) {
        delete iter->second;
    }
}

IFunction *FunctionRegister::Node::getFunc(const size_t &agrsNum) {
    if (functions.size() < agrsNum + 1) {
        return nullptr;
    }

    return functions[agrsNum];
}

bool FunctionRegister::add(const std::string &name, const size_t &argsNum, IFunction *function) {
    Node* currNode = &rood;
    for (int i = 0; i < name.length(); ++i) {
        currNode = currNode->addNote(name[i]);
    }
    return  currNode->addFunc(argsNum, function);
}

IFunction *FunctionRegister::get(const std::string &name, const size_t &argsNum) {
    Node* currNode = &rood;
    for (int i = 0; i < name.length(); ++i) {
        currNode = currNode->getNote(name[i]);
        if (currNode == nullptr) {
            return nullptr;
        }
    }
    return currNode->getFunc(argsNum);
}

FunctionRegister::FunctionRegister() {
    add("eq", 2, new EqFunction());
    add("le", 2, new LeFunction());
    add("nand", 2, new NandFunction());
    add("length", 1, new LengthFunction());
    add("head", 1, new HeadFunction());
    add("tail", 1, new TailFunction());
    add("list", 1, new ListZeroFunction());
    add("list", 2, new ListOneFunction());
    add("list", 3, new ListTwoFunction());
    add("concat", 2, new ConcatFunction());
    add("if", 3, new IfFunction());
    add("read", 0, new ReadFunction());
    add("write", 1, new WriteFunction());
    add("int", 1, new IntFunction());

    add("add", 2, new AddFunction());
    add("sub", 2, new SubFunction());
    add("mul", 2, new MulFunction());
    add("div", 2, new DivFunction());
    add("mod", 2, new ModFunction());
    add("sqrt", 1, new SqrtFunction());
}
