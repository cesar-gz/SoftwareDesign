#pragma once
#include "Automobile.hpp"

class tank : public Automobile
{
public:
  tank();
  tank(int yr, std::string clr, std::string nm);

  void drive();
  void hover();
  void sail();
  void hide();
  void protect();
  void connectBluetooth();
  void turnOnAC();
  void turnOnMediaPlayer();
  void lowerWindows();
  void windshieldWipers();
  void fireBazooka();

protected:
  int tankYear;
  std::string tankColor;
  std::string tankName;
};
