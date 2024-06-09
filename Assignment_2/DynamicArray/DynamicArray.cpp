#include <iostream>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray() {
    rows = 0;
    cols = 0;
    capacity = 0;
    data = nullptr;
}

DynamicArray::DynamicArray(char **data, size_t rows, size_t cols, size_t capacity) {
    this->rows = rows;
    this->cols = cols;
    this->capacity = capacity;
    this->data = data;
}

DynamicArray::~DynamicArray() {
    for(size_t i = 0; i < this->capacity; i++) {
        delete[] this->data[i];
    }
}

size_t DynamicArray::getCapacity() const {
    return this->capacity;
}

void DynamicArray::Resize(size_t newValueSize) {
    size_t oldCapacity = getCapacity();
    size_t newCapacity = oldCapacity + newValueSize;
    char **newData = new char*[capacity];

    for(size_t i = 0; i < oldCapacity; i++) {
        newData[i] = this->data[i];
    }

    for(size_t i = oldCapacity; i < newCapacity; i++) {
        newData[i] = new char[newCapacity];
    }

    delete[] this->data;

    this->data = newData;
    this->capacity = newCapacity;
}

void DynamicArray::PushBack(char *newValue) {

    size_t newValueLength = strlen(newValue);
    Resize(newValueLength);

    for (size_t i = 0; i < newValueLength; i++) {
        this->data[this->rows][this->cols] = newValue[i];
        this->cols++;
    }
}

void DynamicArray::AddNewline() {
    PushBack(const_cast<char*>("\0"));
    this->rows++;
    this->cols = 0;
    char **newData = new char*[this->rows+1];
    for (size_t i = 0; i < this->rows; ++i) {
        newData[i] = this->data[i];
    }
    newData[this->rows] = new char[this->capacity];
    newData[this->rows][0] = '\0';

    delete[] data;
    this->data = newData;
}

void DynamicArray::Print() const {
    for (size_t i = 0; i <= this->rows; i++) {
        size_t j = 0;
        while (this->data[i][j] != '\0') {
            cout << this->data[i][j];
            j++;
        }
        cout << endl;
    }
}
