#include <iostream>
#include "SemiTruck.hpp"

SemiTruck::SemiTruck() {}

SemiTruck::SemiTruck(int YEAR, std::string COLOR, std::string NAME)
{
  customizeCar(YEAR, COLOR, NAME);
}

void SemiTruck::drive() {
  std::cout << "Truck Driving Mode Activated" << '\n';
  std::cout << "You are ready to drive long distances across the states."
            << "\n\n";
}
void SemiTruck::hover()  {
  std::cout << "Truck Hovering Mode Activated" << '\n';
  std::cout << "(You feel the 18 wheels tuck into the truck, and the strong jets start" << '\n';
  std::cout << "You are now somehow safely 10 feet above the ground. You may continue to truck now."
            << "\n\n";
}
void SemiTruck::sail()  {
  std::cout << "Truck Sailing Mode Activated" << '\n';
  std::cout << "(You feel the 18 wheels tuck into the car, and the back yacht propellor lower)" << '\n';
  std::cout << "You are now safely floating in the water. You may continue to truck now."
            << "\n\n";
}
void SemiTruck::hide()
{
  std::cout << "Truck Hiding Mode Activated" << '\n';
  std::cout << "(You notice the truck begin to shine and then turn transparent.)" << '\n';
  std::cout << "You are now hidden. No one can see inside or outside of the truck. You may continue to truck at other's risk."
            << "\n\n";
}
void SemiTruck::protect()
{
  std::cout << "Truck Protection Mode Activated" << '\n';
  std::cout << "(You notice the a camera light turn on the hood)" << '\n';
  std::cout << "AI is monitoring your surroundings. It will now move the truck away from harm. Everyone should be scared."
            << "\n\n";
}
void SemiTruck::connectBluetooth()
{
  std::cout << "Bluetooth Connect Activated to the Truck" << '\n';
  std::cout << "Your phone is now connected to the Truck's Media Player System."
            << "\n\n";
}
void SemiTruck::turnOnAC()
{
  std::cout << "Air Conditioning Activated inside the Truck's Cabin" << '\n';
  std::cout << "(You feel nice cool hair hit you)" << '\n';
  std::cout << "You may continue to truck now."
            << "\n\n";
}
void SemiTruck::turnOnMediaPlayer()
{
  std::cout << "Media Player Activated, Country's top 100 shows on the display." << '\n';
  std::cout << "(Your favorite driving playlist starts playing)"
            << "\n\n";
}
void SemiTruck::lowerWindows()
{
  std::cout << "Power Windows Activated, your dog looks out the window to get fresh air" << '\n';
  std::cout << "(The window lowers, and you feel the fresh air enter the trucks's cabin.)"
            << "\n\n";
}
void SemiTruck::windshieldWipers()
{
  std::cout << "Strong Windshield Wipers Activated" << '\n';
  std::cout << "(The wiper begins to turn on intervals, brushing the rain, mud, and bugs away)"
            << "\n\n";
}
void SemiTruck::haulLoad()
{
  std::cout << "You hook onto a trailer, release the brakes, and start driving with an added 40,000 lbs."
            << "\n\n";
}
