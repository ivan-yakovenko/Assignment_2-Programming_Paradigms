#include "Stack.h"

template <typename T>

Stack<T>::Stack() {
    top = nullptr;
    size = 0;
};

template <typename T>

Stack<T>::~Stack() {
    while (!IsEmpty()) {
        Pop();
    }
}

template <typename T>

void Stack<T>::Push(T value) {
    size++;

    if(top == nullptr) {
        top = new Element;
        top->value = value;
        return;
    }

    Element* temp = new Element;
    temp->value = value;
    temp->pNext = top;
    top = temp;
}

template <typename T>

T &Stack<T>::GetTop() {
    return top->value;
}

template <typename T>

bool Stack<T>::IsEmpty() const {
    return top == nullptr;
}

template <typename T>

void Stack<T>::Pop() {
    if(top == nullptr) {
        return;
    }

    Element* temp = top;
    top = top->pNext;
    delete temp;
    size--;
}






