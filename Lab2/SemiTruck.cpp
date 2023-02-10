#include <iostream>
#include "SemiTruck.hpp"

  SemiTruck(std::string name){
    _name = name;
  }

  virtual void drive() const{
    std::cout << "Driving Mode Activated" << '\n';
    std::cout << "You may now drive where ever you wish"
              << "\n\n";
  }
  virtual void hover() const {
    std::cout << "Hover Mode Activated" << '\n';
    std::cout << "(You feel the wheels tuck into the car, and the jets start" << '\n';
    std::cout << "You are now safely 10 feet above the ground. You may continue to drive now."
              << "\n\n";
  }
  virtual void sail() const {
    std::cout << "Sail Mode Activated" << '\n';
    std::cout << "(You feel the wheels tuck into the car, and the back propellor lower)" << '\n';
    std::cout << "You are now safely floating in the water. You may continue to drive now."
              << "\n\n";
  }
  virtual void hide() const {
    std::cout << "Hide Mode Activated" << '\n';
    std::cout << "(You notice the car begin to shine and then turn transparent.)" << '\n';
    std::cout << "You are now hidden. No one can see inside or outside of the car. You may continue to drive at your own risk."
              << "\n\n";
  }
  virtual void protect() const {
    std::cout << "Protect Mode Activated" << '\n';
    std::cout << "(You notice the a camera light turn on the hood and trunk)" << '\n';
    std::cout << "AI is monitoring your surroundings. It will now move the car away from harm. You may continue to drive."
              << "\n\n";
  }
  virtual void connectBluetooth() const {
    std::cout << "Bluetooth Connect Activated" << '\n';
    std::cout << "Your phone is now connected to the Media Player System."
              << "\n\n";
  }
  virtual void turnOnAC() const {
    std::cout << "Air Conditioning Activated" << '\n';
    std::cout << "(You feel nice cool hair hit you)" << '\n';
    std::cout << "You may continue to drive now."
              << "\n\n";
  }
  virtual void turnOnMediaPlayer() const {
    std::cout << "Media Player Activated" << '\n';
    std::cout << "(Your favorite driving playlist starts playing)"
              << "\n\n";
  }
  virtual void lowerWindows() const {
    std::cout << "Power Windows Activated" << '\n';
    std::cout << "(The window lowers, and you feel the fresh air enter the car's cabin.)"
              << "\n\n";
  }
  virtual void windshieldWipers() const {
    std::cout << "Windshield Wipers Activated" << '\n';
    std::cout << "(The wiper begins to turn on intervals, brushing the rain away)"
              << "\n\n";
  }
  virtual void haulLoad() const {
    std::cout << "You hook onto a trailer, release the brakes, and start driving with an added 40,000 lbs."
              << "\n\n";
  }

  virtual ~SemiTruck() = default;
