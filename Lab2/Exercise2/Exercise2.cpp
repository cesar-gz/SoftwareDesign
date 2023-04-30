#include "Automobile.hpp"
#include "SemiTruck.hpp"
#include "tank.hpp"

namespace
{
  // Code to the interface
  void use_my_automobiles(Automobile &myAuto)
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
  semiTruck Mack;
  use_my_automobiles(Mack);
  Mack.haul();

  tank Destroyer;
  use_my_automobiles(Destroyer);
  Destroyer.fire();
}
