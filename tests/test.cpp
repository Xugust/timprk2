#include "catch2/catch.hpp"
#include "Circle.h"
#include "Square.h"
#include "Shape.h"

#include <cstdlib>

TEST_CASE("Shape constructor") {
    Circle circle{3.14};
    auto drawer = [](Circle const& c) { /*...*/ };
    Shape shape(circle, drawer);

    REQUIRE(shape.get_radius() == 3.14);
    REQUIRE(shape.get_area() == Approx(3.14 * 3.14));
}

TEST_CASE("Shape copy constructor") {
    Circle circle{3.14};
    auto drawer = [](Circle const& c) { /*...*/ };
    Shape shape1(circle, drawer);
    Shape shape2(shape1);

    REQUIRE(shape2.get_radius() == 3.14);
    REQUIRE(shape2.get_area() == Approx(3.14 * 3.14));
}

TEST_CASE("draw function") {
    Circle circle{3.14};
    auto drawer = [](Circle const& c) { /*...*/ };
    Shape shape(circle, drawer);

    bool was_called = false;
    auto mock_drawer = [&was_called](Circle const& c) { was_called = true; };

    draw(shape, mock_drawer);

    REQUIRE(was_called);
}

int main()
{
   // Create a circle as one representative of a concrete shape type
   Circle circle{ 3.14 };

   // Create a drawing strategy in form of a lambda
   auto drawer = []( Circle const& c ){ /*...*/ };

   // Combine the shape and the drawing strategy in a 'Shape' abstraction
   // This constructor call will instantiate a 'detail::OwningShapeModel' for
   // the given 'Circle' and lambda types
   Shape shape1( circle, drawer );

   // Draw the shape
   draw( shape1 );

   // Create a copy of the shape by means of the copy constructor
   Shape shape2( shape1 );

   // Drawing the copy will result in the same output
   draw( shape2 );

   return EXIT_SUCCESS;
}

