#include <iostream>
#include "tank.hpp"

tank::tank() {}

tank::tank(int yr, std::string clr, std::string nm)
{
  customizeCar(yr, clr, nm);
}

void tank::drive()
{
  std::cout << "Killer Tank Running Over Cars Mode Activated" << '\n';
  std::cout << "You are ready to plow over traffic."
            << "\n\n";
}
void tank::hover()
{
  std::cout << "Tank Hovering Mode Activated" << '\n';
  std::cout << "You are now somehow safely 10 feet above the ground. You may continue to plow forward now."
            << "\n\n";
}
void tank::sail()
{
  std::cout << "Tank Sailing Mode Activated" << '\n';
  std::cout << "You are now safely floating in the water. You may continue to slowly drive the tank forward now."
            << "\n\n";
}
void tank::hide()
{
  std::cout << "Tank Hiding Mode Activated" << '\n';
  std::cout << "(You notice the tank begin to shine and then turn transparent.)" << '\n';
  std::cout << "You are now hidden. No one can see inside or outside of the tank. Your Enemies Cower."
            << "\n\n";
}
void tank::protect()
{
  std::cout << "Tank Protection Mode Activated" << '\n';
  std::cout << "(The Tank starts speaking)" << '\n';
  std::cout << "AI is monitoring your surroundings. Everyone including you should be scared."
            << "\n\n";
}
void tank::connectBluetooth()
{
  std::cout << "Bluetooth Connect Activated to the Tank" << '\n';
  std::cout << "Your phone is now connected to the Tank's Media Player System."
            << "\n\n";
}
void tank::turnOnAC()
{
  std::cout << "Air Conditioning Activated inside the Tank's Cabin" << '\n';
}
void tank::turnOnMediaPlayer()
{
  std::cout << "Media Player Activated, Top Metal 100 songs shows on the display." << '\n';
  std::cout << "(Your favorite driving playlist starts playing)"
            << "\n\n";
}
void tank::lowerWindows()
{
  std::cout << "(The tank has no windows to lower or raise)"
            << "\n\n";
}
void tank::windshieldWipers()
{
  std::cout << "The tanks Windshield Wipers Activated" << '\n';
  std::cout << "(The wiper begins to turn on intervals, brushing the enemies blood away)"
            << "\n\n";
}
void tank::fireBazooka()
{
  std::cout << "The tank takes aim. Fire one powerful shot ahead, destroying all that is in your path."
            << "\n\n";
}
