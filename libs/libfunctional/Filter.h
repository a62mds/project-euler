#ifndef FILTER_H
#define FILTER_H

#include <functional>
#include <vector>

namespace functional {

template <typename T>
std::vector<T> filter(const std::vector<T>& input, std::function<bool(const T&)> key) {

	std::vector<T> output;
	for (const T& x : input) {
		if (key(x)) {
			output.push_back(x);
		}
	}

	return output;
}

}; // namespace functional

#endif
