#include <vector>

#include "sum_integers.hpp"

int main() {
    auto integers = { 1, 2, 3, 4 };

    if (sum_integers(integers) == 10) {
        return 0;
    } else {
        return 1;
    }
}
