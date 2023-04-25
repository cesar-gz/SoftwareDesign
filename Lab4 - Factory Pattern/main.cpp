#include "System/Automobile.hpp"

namespace
{
  // Code to the interface
  void use_my_automobiles(System::Automobile &myAuto)
  {
    myAuto.generateReport();
    myAuto.generateReport("Nov 20 1995");
    myAuto.generateReport("Nov 20 1995", "Feb 23 2023");

    myAuto.drive();
    myAuto.sail();
    myAuto.hover();
    myAuto.hide();
    myAuto.protect();
  }
} // namespace

int main()
{
  auto semiTruck = System::Automobile::placeOrder( "semiTruck" );
  use_my_automobiles( *semiTruck );

  auto tank = System::Automobile::placeOrder( "tank" );
  use_my_automobiles( *tank );
}
