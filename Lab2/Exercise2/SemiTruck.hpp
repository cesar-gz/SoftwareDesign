#pragma once
#include "Automobile.hpp"

class SemiTruck : public Automobile
{
public:
  SemiTruck();
  SemiTruck(int YEAR, std::string COLOR, std::string NAME);

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
  void haulLoad();

protected:
  int truckYear;
  std::string truckColor;
  std::string truckName;
};
