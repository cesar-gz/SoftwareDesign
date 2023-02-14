// declaration file
#pragma once
#include <vector>
#include <string>

class Automobile{

  public:
    // constructors
    Automobile();
    Automobile(int year, std::string color, std::string name);

    // 10  features
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

    // setters
    void  setFeature( int x );
    void  setReport( int x , int y , int z);
    void  setPower(int x);

    // getters
    int   getYear();
    int   getMileage();
    int   getGas();
    int   getStartDate();
    int   getEndDate();
    bool  getPower();
    std::string getColor();
    std::string getName();

    // misc
    void generateReport();
    void generateReport(bool x);
    void generateReport(bool y, bool z);
    void addToGarage(Automobile &x);
    void showCars(int x);
    void customizeCar(int Year, std::string Color, std::string Name);
    void selectCar(int x);

  protected:

    // variables
    int year, mileage, gas, randomMileage, randomGasTank, randomCondition, startDate, endDate, value;
    std::string carsHealth, color, name;
    bool power, startDateWanted, endDateWanted;
    std::vector<Automobile> garage;
};
