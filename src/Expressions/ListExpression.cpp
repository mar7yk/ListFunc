//
// Created by Marty Kostov on 22.07.22.
//

#include "ListExpression.hpp"

ListExpression::ListExpression(ExecutableExpression *head, ListExpression *tail) : head(head), tail(tail) {}

ListExpression::~ListExpression() {
    delete head;
    delete tail;
}

ExecutableExpression *ListExpression::get(const std::vector<ExecutableExpression*> &customArgs) {
    return this;
}

IExecutable *ListExpression::getComparable() {
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

ExecutableExpression *ListExpression::getHead() {
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

std::string ListExpression::execute() {
    if (!head) {
        assert(tail == nullptr);
        return "[]";
    }

    std::string result = "[";

    result += head->execute();

    if (tail) {
        result += tail->executeValues();
    }

    result += "]";

    return result;
}

std::string ListExpression::executeValues() {
    if (!head) {
        return "";
    }
    std::string result = " " + head->execute();
    if (tail) {
        result += tail->executeValues();
    }
    return result;
}

ListViewExpression::ListViewExpression(ExecutableExpression *head, ListExpression *tail)
        : ListExpression(head, tail) {}

ListViewExpression::~ListViewExpression() {
    head = nullptr;
}
