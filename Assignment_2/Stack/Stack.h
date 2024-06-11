#pragma once
#include <iostream>

template <typename T>
class Stack {
private:
    struct Element {
        T value = T();
        Element* pNext = nullptr;
    };
    Element* top;
    size_t size;
public:
    Stack();
    ~Stack();
    void Push(T value);
    T& GetTop();
    bool IsEmpty() const;
    void Pop();
};
