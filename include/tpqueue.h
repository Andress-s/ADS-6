// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
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

    // добавление элемента в очередь с учетом приоритета
    void push(char ch, int prior) {
        SYM* temp = new SYM{ ch, prior, nullptr };

        if (!head) {
            head = temp;
            tail = temp;
        }
        else if (prior > head->prior) {
            temp->next = head;
            head = temp;
        }
        else {
            SYM* current = head;
            while (current->next && prior <= current->next->prior)
                current = current->next;
            temp->next = current->next;
            current->next = temp;
        }
    }

    // удаление элемента из очереди
    void pop() {
        if (!head)
            return;

        SYM* temp = head;
        head = head->next;
        delete temp;
    }

    // проверка очереди на пустоту
    bool isEmpty() const {
        return head == nullptr;
    }

    // вывод очереди на экран
    friend ostream& operator<<(ostream& os, const TPQueue& q) {
        SYM* current = q.head;
        while (current) {
            os << '[' << current->ch << ':' << current->prior << ']';
            current = current->next;
        }
        return os;
    }
};

struct SYM {
    char ch;
    int prior;
    SYM* next;
};

#endif  // INCLUDE_TPQUEUE_H_
