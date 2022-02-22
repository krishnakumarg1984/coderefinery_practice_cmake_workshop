#include <vector>

#include "sum_integers.hpp"

// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Sum of integers for a short vector", "[short]") {
    auto integers = { 1, 2, 3, 4, 5 };
    REQUIRE(sum_integers(integers) == 15);
}

TEST_CASE("Sum of integers for a longer vector", "[long]") {
    std::vector<int> integers;
    int max_value_in_vector { 1000 };
    for (int i { 1 }; i <= max_value_in_vector; ++i) {
        integers.push_back(i);
    }
    // REQUIRE(sum_integers(integers) == 500500);
    REQUIRE(sum_integers(integers) == max_value_in_vector * (max_value_in_vector + 1) / 2);
}
