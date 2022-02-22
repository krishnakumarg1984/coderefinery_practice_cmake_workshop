#include "sum_integers.hpp"

#include <vector>

int sum_integers(const std::vector<int>& integers) {
    auto sum { 0 };
    for (auto i : integers) {
        sum += i;
        // sum -= i;  // to trigger a failing test
    }
    return sum;
}
