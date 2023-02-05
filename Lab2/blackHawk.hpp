// declaration file
#pragma once
#include <vector>

class blackHawk{
  private:
    int  feature;
    int  purchase;
    int  year;
    int  mileage;
    int  gas;
    int  randomMileage;
    int  randomGasTank;
    int  randomCondition;
    int  startDate;
    int  endDate;
    int  result;
    int  value;
    std::string carsHealth;
    std::string color;
    std::string name;
    bool power;
    bool sessionIsActive;
    bool startDateWanted;
    bool endDateWanted;
    std::vector<blackHawk> garage;

  public:
    int option;

    blackHawk();
    blackHawk(int year, std::string color, std::string name);

    int   mainMenu();

    void  queryClient();
    void  customizeCar( int Year , std::string Color , std::string Name );
    void  addToGarage( blackHawk x);
    void  showCars();

    void  generateReport();
    void  generateReport(bool x);
    void  generateReport(bool y, bool z);

    blackHawk selectCar( int x );

    void  setActive( bool y );
    void  setFeature( int x );
    void  setPurchase( int x );
    void  setPower( int x );
    void  setReport( int x , int y , int z);

    int   getYear();
    int   getMileage();
    int   getGas();
    int   getFeature();
    int   getStartDate();
    int   getEndDate();
    bool  getActive();
    bool  getPurchase();
    bool  getPower();
    std::string getColor();
    std::string getName();
};
