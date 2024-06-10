#include <gtest/gtest.h>
#include <memory>

#include <Shape.h>
#include <Circle.h>
#include <Square.h>

TEST(Shape, Small)
{
   auto circle   = Circle(1.0);
   auto square   = Square(2.0);
   auto circle_2 = Circle(3.0);

   {
      Shape shape( circle, [](Circle const& c){ std::cout << "Drawing circle of radius " << c.radius() << "n"; } );
      draw(shape);
   }

   {
      Shape shape( square, [](Square const& s){ std::cout << "Drawing square of side length " << s.side() << "n"; } );
      draw(shape);
   }

   {
      Shape shape( circle_2, [](Circle const& c){ std::cout << "Drawing circle of radius " << c.radius() << "n"; } );
      draw(shape);
   }
}

TEST(Shape, SmallCopy)
{
   auto circle   = Circle(1.0);
   auto circle_2 = Circle(3.0);

   {
      Shape s{circle, [](Circle const&){}};
      Shape s_copy{s};
      draw(s_copy);
   }
   {
      Shape s{circle_2, [](Circle const&){}};
      Shape s_copy{s};
      draw(s_copy);
   }
}

TEST(Shape, SmallMove)
{
   auto circle   = Circle(1.0);
   auto circle_2 = Circle(3.0);

   {
      Shape s{circle, [](Circle const&){}};
      Shape s_move{std::move(s)};
      draw(s_move);
   }

   {
      Shape s{circle_2, [](Circle const&){}};
      Shape s_move{std::move(s)};
      draw(s_move);
   }
}

int main()
{
   testing::InitGoogleTest();
   return RUN_ALL_TESTS();
}

