#include <catch2/catch.hpp>

#include "arrow/vector.hpp"
using namespace arrow;

TEST_CASE("vector subscript", "[vector][subscript]") {
    vector<int, 5> v = {3, 2, 7, 6, 8};
    const vector<int, 5> c = {6, 5, 5, 3, 6};

    SECTION("non-const subscript reading") {
        REQUIRE(v[0] == 3);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 7);
        REQUIRE(v[3] == 6);
        REQUIRE(v[4] == 8);
    }

    SECTION("non-const subscript writing") {
        v[0] = 6;
        v[1] = 5;
        v[2] = 5;
        v[3] = 3;
        v[4] = 6;

        REQUIRE(v == c)
    }

    SECTION("const subscript reading") {
        REQUIRE(c[0] == 6);
        REQUIRE(c[1] == 5);
        REQUIRE(c[2] == 5);
        REQUIRE(c[3] == 3);
        REQUIRE(c[4] == 6);
    }
}

TEST_CASE("vector comparison", "[vector][comparison]") {
    vector<int, 5> a = {1, 1, 2, 3, 5};
    vector<int, 5> b = {1, 1, 2, 3, 5};
    vector<int, 5> c = {5, 4, 3, 2, 1};

    SECTION("self equality") {
        REQUIRE(a == a);
        REQUIRE(b == b);
        REQUIRE(c == c);
    }

    SECTION("self inequality") {
        REQUIRE(!(a != a));
        REQUIRE(!(b != b));
        REQUIRE(!(c != c));
    }

    SECTION("equality") {
        REQUIRE(a == b);
        REQUIRE(b == a);

        REQUIRE(!(b == c));
        REQUIRE(!(c == b));

        REQUIRE(!(a == c));
        REQUIRE(!(c == a));
    }

    SECTION("inequality") {
        REQUIRE(!(a != b));
        REQUIRE(!(b != a));

        REQUIRE(b != c);
        REQUIRE(c != b);

        REQUIRE(a != c);
        REQUIRE(c != a);
    }
}

TEST_CASE("vector arithmetic", "[vector][arithmetic]") {
    vector<int, 5> a = {1, 2, 3, 4, 5};
    vector<int, 5> b = {4, 8, 7, 6, 3};

    SECTION("addition") {
        auto c = a + b;
        auto d = b + a;

        REQUIRE(c == vector<int, 5>{5, 10, 10, 10, 8});
        REQUIRE(d == vector<int, 5>{5, 10, 10, 10, 8});
    }
}
