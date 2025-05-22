#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Simple math test", "[example]") {
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Very NICE") {
    REQUIRE(1 + 2 == 3);
}

TEST_CASE("EXAMPLES", "[tag]") {
    REQUIRE(1 + 1 == 2);
    CHECK(2 * 2 == 5); // Test fail but continues
    SECTION("SUBSECTION") {
        REQUIRE("STRING" == "STRING");
    }
}