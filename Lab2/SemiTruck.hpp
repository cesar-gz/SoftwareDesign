#pragma once
#include "Automobile.hpp"
#include "Automobile.cpp"

class SemiTruck : public Automobile
{
public:
  SemiTruck(std::string name);

  virtual void drive() const = 0;
  virtual void hover() const = 0;
  virtual void sail() const = 0;
  virtual void hide() const = 0;
  virtual void protect() const = 0;
  virtual void connectBluetooth() const = 0;
  virtual void turnOnAC() const = 0;
  virtual void turnOnMediaPlayer() const = 0;
  virtual void lowerWindows() const = 0;
  virtual void windshieldWipers() const = 0;
  virtual void haulLoad() const = 0;

  virtual ~SemiTruck();

protected:
  int _year = 2024;
  std::string _color = "Ground";
  std::string _name = "Mack";
};
