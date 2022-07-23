//
// Created by Marty Kostov on 22.07.22.
//

#include "ListExpression.hpp"

ListExpression::ListExpression(IExpression *head, ListExpression *tail) : head(head), tail(tail) {}

ListExpression::~ListExpression() {
    delete head;
    delete tail;
}

std::string ListExpression::getValues(const std::vector<IExpression *> &args) {
    if (!head) {
        return "";
    }
    std::string result = " " + head->getValue(args);
    if (tail) {
        result += tail->getValues(args);
    }
    return result;
}

std::string ListExpression::getValue(const std::vector<IExpression*> &args) {
    if (!head) {
        assert(tail == nullptr);
        return "[]";
    }

    std::string result = "[";

    result += head->getValue(args);

    if (tail) {
        result += tail->getValues(args);
    }

    result += "]";

    return result;
}

IExpression *ListExpression::get(const std::vector<IExpression *> &args) {
    return this;
}

IExpression *ListExpression::getComparable() {
    assert(!head || tail);
    if (head && !tail->tail) {
        return head;
    }

    return this;
}

int ListExpression::getLength() {
    if (!head) {
        return 0;
    } else if (!tail) {
        return 1;
    }
    return 1 + tail->getLength();
}

IExpression *ListExpression::getHead() {
    return head;
}

ListExpression *ListExpression::getTail() {
    return tail;
}

ListExpression *ListExpression::concat(ListExpression *left, ListExpression *right) {
    assert(left != nullptr);
    assert(right != nullptr);
    if (!left->head) {
        assert(left->tail == nullptr);

        if (!right->head) {
            assert(right->tail == nullptr);

            return new ListViewExpression(nullptr, nullptr);
        }

        return new ListViewExpression(right->head, concat(left, right->tail));
    }

    return new ListViewExpression(left->head, concat(left->tail, right));
}

size_t ListExpression::getParmCount() {
    if (!head) {
        assert(tail == nullptr);
        return 0;
    }

    if (!tail) {
        return head->getParmCount();
    }

    return std::max(head->getParmCount(), tail->getParmCount());
}

ExecutableListExpression::ExecutableListExpression(IExpression *head, ListExpression *tail) : ListExpression(head,
                                                                                                             tail) {}

std::string ExecutableListExpression::executeValues() {
    if (!head) {
        return "";
    }

    auto *item = dynamic_cast<IExecutable *>(head);
    assert(item != nullptr);
    std::string result = " " + item->execute();

    auto *tailItems = dynamic_cast<ExecutableListExpression *>(tail);
    assert(tail == nullptr || tailItems != nullptr);
    if (tailItems) {
        result += tailItems->executeValues();
    }
    return result;
}

std::string ExecutableListExpression::execute() {
    if (!head) {
        assert(tail == nullptr);
        return "[]";
    }

    std::string result = "[";
    auto *item = dynamic_cast<IExecutable *>(head);
    assert(item != nullptr);
    result += item->execute();

    auto *tailItems = dynamic_cast<ExecutableListExpression *>(tail);
    assert(tail == nullptr || tailItems != nullptr);
    if (tailItems) {
        result += tailItems->executeValues();
    }

    result += "]";

    return result;
}

size_t ExecutableListExpression::getParmCount() {
    return 0;
}

ListViewExpression::ListViewExpression(IExpression *head, ListExpression *tail)
        : ListExpression(head, tail) {}

ListViewExpression::~ListViewExpression() {
    head = nullptr;
}
