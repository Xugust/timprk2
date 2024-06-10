#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "Circle.h"
#include "Shape.h"
#include "Square.h"
#include <iostream>
#include <sstream>

TEST_CASE("Create a Circle and draw it using Shape") {
    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    Circle circle{3.14};
    auto drawer = [](Circle const& c) { std::cout << "Drawing circle with radius: " << c.getRadius(); };
    Shape shape(circle, drawer);

    draw(shape);

    std::cout.rdbuf(old);
    REQUIRE(output.str() == "Drawing circle with radius: 3.14");
}

TEST_CASE("Copy construct a Shape object") {
    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    Circle circle{3.14};
    auto drawer = [](Circle const& c) { std::cout << "Drawing circle with radius: " << c.getRadius(); };
    Shape shape1(circle, drawer);

    Shape shape2(shape1);
    draw(shape2);

    std::cout.rdbuf(old);
    REQUIRE(output.str() == "Drawing circle with radius: 3.14");
}

TEST_CASE("Create a Square and draw it using Shape") {
    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    Square square{4.0};
    auto drawer = [](Square const& s) { std::cout << "Drawing square with side: " << s.getSide(); };
    Shape shape(square, drawer);

    draw(shape);

    std::cout.rdbuf(old);
    REQUIRE(output.str() == "Drawing square with side: 4");
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

