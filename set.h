#ifndef SET_H
#define SET_H

#include <iostream>
#include <random>

using namespace std;

template<typename T>
class set {
private:
    T* _data;
    size_t _capacity;
    size_t _size;
    inline static const double _epsilon = 1e-9;
public:
    set();
    ~set();
};

#endif
