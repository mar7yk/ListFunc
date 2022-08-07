//
// Created by Marty Kostov on 24.07.22.
//

#ifndef LISTFUNC_MEMORYMANAGER_HPP
#define LISTFUNC_MEMORYMANAGER_HPP

#include <stack>

#include "Expressions/IExpression.hpp"


class MemoryManager {
    static MemoryManager *manager;
    static MemoryManager *GetInstance();
    MemoryManager() = default;

    std::stack<IExecutable *> tempExpressions;
public:
    MemoryManager(MemoryManager &other) = delete;
    void operator=(const MemoryManager &other) = delete;

    ///registers expression to by deleted from #CleanTempExpression()
    static void AddTempExpression(IExecutable * expression);

    ///delete all expressions registers from #AddTempExpression(IExecutable * expression)
    static void CleanTempExpression();
};

#endif //LISTFUNC_MEMORYMANAGER_HPP
