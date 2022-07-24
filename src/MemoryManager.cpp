//
// Created by Marty Kostov on 24.07.22.
//

#include "MemoryManager.hpp"

MemoryManager *MemoryManager::manager = nullptr;

MemoryManager *MemoryManager::GetInstance() {
    if (!manager) {
        manager = new MemoryManager();
    }
    return manager;
}

void MemoryManager::AddTempExpression(IExpression *expression) {
    MemoryManager *memoryManager = GetInstance();
    memoryManager->tempExpressions.push(expression);
}

void MemoryManager::CleanTempExpression() {
    MemoryManager *memoryManager = GetInstance();
    std::stack<IExpression *> &tempExpressions = memoryManager->tempExpressions;
    while (!tempExpressions.empty()) {
        delete tempExpressions.top();
        tempExpressions.pop();
    }
}
