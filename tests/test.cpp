#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Buffer.h"

TEST_CASE("Buffer class tests", "[Buffer]") {
    SECTION("Default constructor") {
        Buffer<int> buffer;
        REQUIRE(buffer.size() == 0);
        REQUIRE(buffer.capacity() == Buffer<int>::small_capacity);
    }

    SECTION("Parameterized constructor") {
        Buffer<int> buffer(10);
        REQUIRE(buffer.size() == 0);
        REQUIRE(buffer.capacity() == 10);
    }

    SECTION("Append and size") {
        Buffer<int> buffer;
        buffer.append(1);
        buffer.append(2);
        buffer.append(3);
        REQUIRE(buffer.size() == 3);
    }
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

