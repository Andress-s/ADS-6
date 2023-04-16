// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <ostream>

struct SYM {
    char ch;
    int prior;
    SYM* next;
};
template <class T, int size>
class TPQueue {
 private:
    SYM* head;
    SYM* tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue() {
        while (head)
            pop();
    }
    void push(SYM a) {
        SYM* temp = new SYM{ a.ch, a.prior, nullptr };
        if (!head) {
            head = temp;
            tail = temp;
        } else if (a.prior > head->prior) {
            temp->next = head;
            head = temp;
        } else {
            SYM* current = head;
            while (current->next && a.prior <= current->next->prior)
                current = current->next;
            temp->next = current->next;
            current->next = temp;
        }
    }
    SYM pop() {
        SYM* temp = head;
        head = head->next;
        return *temp;
    }
    bool isEmpty() const {
        return head == nullptr;
    }
    friend std::ostream& operator<<(std::ostream& os, const TPQueue& q) {
        SYM* current = q.head;
        while (current) {
            os << '[' << current->ch << ':' << current->prior << ']';
            current = current->next;
        }
        return os;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
