// declaration file
#pragma once
#include <vector>

class blackHawk{
  private:
    int  feature;
    int  purchase;
    int  year;
    std::string color;
    std::string name;
    bool   power;
    bool sessionIsActive;
    std::vector<blackHawk> garage;

  public:
    int option;

    blackHawk();
    blackHawk(int year, std::string color, std::string name);

    int   mainMenu();

    void  customizeCar(int Year, std::string Color, std::string Name);
    void  addToGarage( blackHawk x);
    void  showCars();
    blackHawk selectCar(int x);

    void  setActive( bool y );
    void  setFeature( int x );
    void  setPurchase( int x );
    void  setPower( int x );

    int   getFeature();
    bool  getActive();
    bool  getPurchase();
    bool  getPower();
    int   getYear();
    std::string getColor();
    std::string getName();
};

