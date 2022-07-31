//
// Created by Marty Kostov on 31.07.22.
//

#include "GetListFunction.hpp"

ExecutableExpression *GetListFunction::get(const std::vector<IExpression *> &args, const std::vector<ExecutableExpression*> &customArgs) {
    auto list = new ListViewExpression(nullptr, nullptr);
    for (size_t i = args.size(); i > 0; --i) {
        ExecutableExpression *item = args[i - 1]->get(customArgs);
        list = new ListViewExpression(item, list);
    }
    MemoryManager::AddTempExpression(list);
    return list;
}
