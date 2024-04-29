#ifndef MAP_H
#define MAP_H

#include <functional>
#include <vector>

namespace functional {

template <typename T, typename U>
std::vector<U> map(const std::vector<T>& input, std::function<U(T)> func) {

	std::vector<U> output;
	for (const T& x : input) {
		output.push_back(func(x));
	}

	return output;
}

template <typename T, typename U>
std::vector<U> map(const std::vector<T>& input, std::function<U(const T&)> func) {

	std::vector<U> output;
	for (const T& x : input) {
		output.push_back(func(x));
	}

	return output;
}

}; // namespace functional

#endif
