#pragma once
#include <iostream>

class DynamicArray {
private:
    char **data;
    size_t rows;
    size_t cols;
    size_t capacity;
public:
    DynamicArray();
    DynamicArray(char** data, size_t rows, size_t cols, size_t capacity);
    ~DynamicArray();
    size_t getCapacity() const;
    void Resize(size_t newValueSize);
    void PushBack(char* newValue);
    void AddNewline();
    void Insert(int line, int index, char *newValue);
    void Search(char* text);
    void SaveInfo(char* filename);
    void LoadInfo(char* filename);
    void Delete(int line, int index, int symbols);
    void Print() const;
};
