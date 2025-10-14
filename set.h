#ifndef SET_H
#define SET_H

#include <iostream>
#include <random>
#include <cmath>
#include <stdexcept>

using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

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
        }
        else {
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

    bool is_equal(double a, double b) const {
        return abs(a - b) <= _epsilon;
    }

public:
    set() : _data(nullptr), _capacity(0), _size(0) {}

    set(const T* values, size_t count) : _data(nullptr), _capacity(0), _size(0) {
        for (size_t i = 0; i < count; ++i) {
            add(values[i]);
        }
    }

    set(size_t count, const T& min_value, const T& max_value) : _data(nullptr), _capacity(0), _size(0) {
        if (count > 0) {
            random_device rd;
            mt19937 gen(rd());

            uniform_int_distribution<T> dis(min_value, max_value);
            
            for (size_t i = 0; i < count; ++i) {
                add(dis(gen));
            }
        }
    }

    void add(const T& value) {
        
        if (!contains(value)) {
            
            if (_size >= _capacity) {
                size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
                resize(new_capacity);
            }

            _data[_size++] = value;
        }
    }

    void remove(const T& value) {
        for (size_t i = 0; i < _size; ++i) {
            if (is_equal(_data[i], value)) {
                for (size_t j = i; j < _size - 1; ++j) {     // shift elements
                    _data[j] = _data[j + 1];
                }
                --_size;
                break;
            }
        }
    }

    bool has(const T& value) const {
        return contains(value);
    }

    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw out_of_range("Index out of range");
        }
        return _data[index];
    }

    set operator+(const set& other) const {
        set result(*this);                      // create copy actual
        for (size_t i = 0; i < other._size; ++i) {
            result.add(other._data[i]);
        }
        return result;
    }

    set operator-(const set& other) const {
        set result;
        for (size_t i = 0; i < _size; ++i) {
            if (!other.contains(_data[i])) {
                result.add(_data[i]);
            }
        }
        return result;
    }

    set operator+(const T& value) const {  // for set+num
        set result(*this);
        result.add(value);
        return result;
    }

    set operator-(const T& value) const {   // for set-num
        set result(*this);
        result.remove(value);
        return result;
    }
    
    set& operator+=(const T& value) {
        add(value);
        return *this;
    }

    set& operator-=(const T& value) {
        remove(value);
        return *this;
    }

    set intersection(const set& other) const {
        set result;
        for (size_t i = 0; i < _size; ++i) {
            if (other.contains(_data[i])) {
                result.add(_data[i]);
            }
        }
        return result;
    }

    bool is_subset_of(const set& other) const {
        for (size_t i = 0; i < _size; ++i) {
            if (!other.contains(_data[i])) {
                return false;
            }
        }
        return true;
    }

    bool is_superset_of(const set& other) const {
        return other.is_subset_of(*this);
    }

    size_t get_size() const {
        return _size;
    }

    bool is_empty() const {
        return _size == 0;
    }

    bool operator==(const set& other) const {
        if (_size != other._size) {
            return false;
        }
        for (size_t i = 0; i < _size; ++i) {
            if (!other.contains(_data[i])) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const set& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const set& set_obj) {
        os << "{";
        for (size_t i = 0; i < set_obj._size; ++i) {
            os << set_obj._data[i];
            if (i < set_obj._size - 1) {
                os << ", ";
            }
        }
        os << "}";
        return os;
    }
};

#endif
