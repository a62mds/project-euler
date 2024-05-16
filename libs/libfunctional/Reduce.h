#ifndef REDUCE_H
#define REDUCE_H

#include <functional>
#include <vector>

namespace functional {

template <typename T>
T reduce(const std::vector<T>& input, T init, std::function<T(T, T)> func) {

    T output = init;
    for (const T& x : input) {
        output = func(output, x);
    }

    return output;
}

template <typename T>
T reduce(const std::vector<T>& input, T init, std::function<T(const T&, const T&)> func) {

    T output = init;
    for (const T& x : input) {
        output = func(output, x);
    }

    return output;
}

}; // namespace functional

#endif
