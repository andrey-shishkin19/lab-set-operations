#ifndef SET_H
#define SET_H

#include <iostream>
#include <random>
#include <cmath>
#include <stdexcept>
#include <string>
#include <algorithm>

template<typename T>
class set {
private:
    T* _data;
    size_t _capacity;
    size_t _size;
    inline static const double _epsilon = 0.001;

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

    bool is_equal(const T& a, const T& b) const {
        //std::cout << "regular equal\n";
        return a == b;
    }

public:

    set() : _data(nullptr), _capacity(0), _size(0) {}

    set(const T* values, size_t count) : _data(nullptr), _capacity(0), _size(0) {
        for (size_t i = 0; i < count; ++i) {
            add(values[i]);
        }
    }

    set(size_t count, int min_value, int max_value) : _data(nullptr), _capacity(0), _size(0) {
        if (count > 0) {
            std::random_device engine;
            std::uniform_int_distribution<int> distribution(std::min(min_value, max_value), std::max(min_value, max_value));

            for (size_t i = 0; i < count; ++i) {
                int value = distribution(engine);
                while (has(value)) {
                    value = distribution(engine);
                }
                add(value);
            }
        }
    }

    set(size_t count, float min_value, float max_value) : _data(nullptr), _capacity(0), _size(0) {
        if (count > 0) {
            std::random_device engine;
            std::uniform_real_distribution<float> distribution(std::min(min_value, max_value), std::max(min_value, max_value));

            for (size_t i = 0; i < count; ++i) {
                float value = distribution(engine);
                while (has(value)) {
                    value = distribution(engine);
                }
                add(value);
            }
        }
    }

    set(size_t count, double min_value, double max_value) : _data(nullptr), _capacity(0), _size(0) {
        if (count > 0) {
            std::random_device engine;
            std::uniform_real_distribution<double> distribution(std::min(min_value, max_value), std::max(min_value, max_value));

            for (size_t i = 0; i < count; ++i) {
                double value = distribution(engine);
                while (has(value)) {
                    value = distribution(engine);
                }
                add(value);
            }
        }
    }

    set(size_t count, const std::string& min_value, const std::string& max_value) : _data(nullptr), _capacity(0), _size(0) {
        if (count > 0) {
            std::random_device engine;
            std::uniform_int_distribution<int> char_dist('a', 'z');
            std::uniform_int_distribution<size_t> len_dist(1, 6);

            for (size_t i = 0; i < count; ++i) {
                std::string value;
                size_t len = len_dist(engine);
                for (size_t j = 0; j < len; ++j) {
                    value += static_cast<char>(char_dist(engine));
                }
                while (has(value)) {
                    value = "";
                    len = len_dist(engine);
                    for (size_t j = 0; j < len; ++j) {
                        value += static_cast<char>(char_dist(engine));
                    }
                }
                add(value);
            }
        }
    }

    set(size_t count, const std::pair<int, double>& min_value, const std::pair<int, double>& max_value) : _data(nullptr), _capacity(0), _size(0) {
        if (count > 0) {
            std::random_device engine;
            std::uniform_int_distribution<int> first_dist(std::min(min_value.first, max_value.first), std::max(min_value.first, max_value.first));
            std::uniform_real_distribution<double> second_dist(std::min(min_value.second, max_value.second), std::max(min_value.second, max_value.second));

            for (size_t i = 0; i < count; ++i) {
                std::pair<int, double> value = {first_dist(engine), second_dist(engine)};
                while (has(value)) {
                    value = {first_dist(engine), second_dist(engine)};
                }
                add(value);
            }
        }
    }

    
    set(const set& other) : _data(nullptr), _capacity(0), _size(0) {
        if (other._size > 0) {
            _data = new T[other._capacity];
            _capacity = other._capacity;
            _size = other._size;
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
    }

    
    set& operator=(const set& other) {
        if (this != &other) {
            delete[] _data;

            if (other._size > 0) {
                _data = new T[other._capacity];
                _capacity = other._capacity;
                _size = other._size;
                for (size_t i = 0; i < _size; ++i) {
                    _data[i] = other._data[i];
                }
            }
            else {
                _data = nullptr;
                _capacity = 0;
                _size = 0;
            }
        }
        return *this;
    }

    
    ~set() {
        delete[] _data;
    }

    
    void add(const T& value) {
        if (!has(value)) {
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
                for (size_t j = i; j < _size - 1; ++j) {
                    _data[j] = _data[j + 1];
                }
                --_size;
                break;
            }
        }
    }

    bool has(const T& value) const {
        for (size_t i = 0; i < _size; ++i) {
            if (is_equal(_data[i], value)) {
                return true;
            }
        }
        return false;
    }

    
    const T& operator[](size_t index) const {
        if (index >= _size || index <0) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    size_t get_size() const {
        return _size;
    }

    bool is_empty() const {
        return _size == 0;
    }

    
    set operator+(const T& value) const {
        set result(*this);
        result.add(value);
        return result;
    }

    set operator-(const T& value) const {
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

    
    friend std::ostream& operator<<(std::ostream& os, const set& set_obj) {
        os << "{";
        for (size_t i = 0; i < set_obj._size; ++i) {
            os << set_obj._data[i];
            if (i < set_obj._size - 1) {   // if not end
                os << ", ";
            }
        }
        os << "}";
        return os;
    }
};


template<typename T>
set<T> set_union(const set<T>& a, const set<T>& b) {
    set<T> result = a;
    for (size_t i = 0; i < b.get_size(); ++i) {
        result.add(b[i]);
    }
    return result;
}

template<typename T>
set<T> set_difference(const set<T>& a, const set<T>& b) {
    set<T> result;
    for (size_t i = 0; i < a.get_size(); ++i) {
        if (!b.has(a[i])) {
            result.add(a[i]);
        }
    }
    return result;
}

template<typename T>
set<T> set_intersection(const set<T>& a, const set<T>& b) {
    set<T> result;
    for (size_t i = 0; i < a.get_size(); ++i) {
        if (b.has(a[i])) {
            result.add(a[i]);
        }
    }
    return result;
}

template<typename T>
bool is_subset(const set<T>& subset, const set<T>& superset) {
    for (size_t i = 0; i < subset.get_size(); ++i) {
        if (!superset.has(subset[i])) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool is_superset(const set<T>& superset, const set<T>& subset) {
    return is_subset(subset, superset);
}


template<typename T>
set<T> operator+(const set<T>& a, const set<T>& b) {
    return set_union(a, b);
}

template<typename T>
set<T> operator-(const set<T>& a, const set<T>& b) {
    return set_difference(a, b);
}

template<typename T>
bool operator==(const set<T>& a, const set<T>& b) {
    if (a.get_size() != b.get_size()) {
        return false;
    }
    for (size_t i = 0; i < a.get_size(); ++i) {
        if (!b.has(a[i])) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool operator!=(const set<T>& a, const set<T>& b) {
    return !(a == b);
}


template<>
bool set<float>::is_equal(const float& a, const float& b) const {
    //std::cout << "float equal\n";
    return std::fabs(a - b) <= _epsilon;
}

template<>
bool set<double>::is_equal(const double& a, const double& b) const {
    //std::cout << "double equal\n";
    return std::fabs(a - b) <= _epsilon;
}

template<>
bool set<std::pair<int, double>>::is_equal(const std::pair<int, double>& a, const std::pair<int, double>& b) const {
    bool first_equal = (a.first == b.first);
    bool second_equal = (std::fabs(a.second - b.second) <= _epsilon);
    //std::cout << "pair equal\n";
    return first_equal && second_equal;
}



template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

#endif
