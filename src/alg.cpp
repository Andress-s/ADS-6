// Copyright 2021 NNTU-CS
#include <iostream>
using namespace std;

// структура для хранения элемента очереди с приоритетом
struct SYM {
    char ch;
    int prior;
    SYM* next;
};

// класс для реализации очереди с приоритетом
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
    void push(char ch, int prior) {
        SYM* temp = new SYM{ ch, prior, nullptr };

        if (!head) {
            head = temp;
            tail = temp;
        }
        else if (prior > head->prior) {
            temp->next = head;
            head = temp;
        } else {
            SYM* current = head;
            while (current->next && prior <= current->next->prior)
                current = current->next;
            temp->next = current->next;
            current->next = temp;
        }
    }
    void pop() {
        if (!head)
            return;

        SYM* temp = head;
        head = head->next;
        delete temp;
    }
    bool isEmpty() const {
        return head == nullptr;
    }
    friend ostream& operator<<(ostream& os, const TPQueue& q) {
        SYM* current = q.head;
        while (current) {
            os << '[' << current->ch << ':' << current->prior << ']';
            current = current->next;
        }
        return os;
    }
};
