#ifndef SET_H
#define SET_H

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

template<typename T>
class set {
private:
    T* _data;
    size_t _capacity;
    size_t _size;
    inline static const double _epsilon = 1e-9;

    void resize(size_t new_capacity) {
    if (new_capacity == 0) {
        delete[] _data;
        _data = nullptr;
        _capacity = 0;
        _size = 0;
        return;
    }

    T* new_data = new T[new_capacity];

    size_t elements_to_copy = (_size < new_capacity) ? _size : new_capacity;
    for (size_t i = 0; i < elements_to_copy; ++i) {
        new_data[i] = _data[i];
    }

    delete[] _data;
    _data = new_data;
    _capacity = new_capacity;

    if (_size > new_capacity) {
        _size = new_capacity;
    }
}

bool contains(const T& value) const {
    for (size_t i = 0; i < _size; ++i) {
        if (is_equal(_data[i], value)) {
            return true;
        }
    }
    return false;
}

bool is_equal(const T& a, const T& b) const {
    return a == b;
}

public:
    set() : _data(nullptr), _capacity(0), _size(0) {}

    set(const T* values, size_t count) : _data(nullptr), _capacity(0), _size(0) {
        for (size_t i = 0; i < count; ++i) {
            add(values[i]);
        }
    }

    set(size_t count, const T& min_value, const T& max_value) : _data(nullptr), _capacity(0), _size(0) {
        if (count == 0) return;

        random_device rd;
        mt19937 gen(rd());

        
        for (size_t i = 0; i < count; ++i) {
            add(min_value);
        }
    }

    void add(const T& value) {
        if (contains(value)) {
            return;
        }

        if (_size >= _capacity) {
            size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
            resize(new_capacity);
        }
        _data[_size++] = value;
    }

    void remove(const T& value) {
        for (size_t i = 0; i < _size; ++i) {
            if (is_equal(_data[i], value)) {
                for (size_t j = i; j < _size - 1; ++j) {
                    _data[j] = _data[j + 1];
                }
                --_size;
                return;
            }
        }
    }

    bool has(const T& value) const {
        return contains(value);
    }
    
};

#endif
