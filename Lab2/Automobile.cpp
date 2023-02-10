#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "Automobile.hpp"

// Automobile constructor
Automobile::Automobile(){}

Automobile::Automobile(int Year, std::string Color, std::string Name){
  customizeCar( Year, Color, Name );
}

// Automobile member functions
void Automobile::customizeCar(int Year, std::string Color, std::string Name){

  while(true){
    std::cout << "We have the new 2023, last years 2022 model, and the original 2021." << '\n';
    std::cout << "What year model would you like?" << '\n';
    std::cout << "Type 2023, 2022, or 2021: ";
    std::cin >> Year;
    std::cout << '\n';

    if ( Year == 2023 || Year == 2022 || Year == 2021){
      break;
    }
    std::cout << "Please choose one of the options." << "\n\n";
  }

  while(true){
    std::cout << "The available colors are Black, Blue, and Red." << '\n';
    std::cout << "What color would you like?" << '\n';
    std::cout << "Type Black, Blue, or Red: " << '\n';
    std::cin >> Color;
    std::cout << '\n';

    if( Color == "Black" || Color == "Blue" || Color == "Red"){
      break;
    }
    std::cout << "Please choose one of the options." << "\n\n";
  }

  std::cout << "What would you like to name your automobile? Please type only one word." << '\n';
  std::cin >> Name;
  std::cout << '\n';

  year = Year;
  color = Color;
  name  = Name;

  srand(static_cast<unsigned>(time(NULL)));
  randomMileage = rand() % 250000;  // generate mileage from 0-250,000
  srand(static_cast<unsigned>(time(NULL)));
  randomGasTank = 1 + rand() % 10;  // generate gas tank size from 1/10 to 10/10
  srand(static_cast<unsigned>(time(NULL)));
  randomCondition = 1 + rand() % 4; // generate random condition from 1 to 4
  setReport(randomMileage, randomGasTank, randomCondition);

  std::cout << "Congratulations, you are the owner of a " << '\n';
  std::cout << getYear() << " " << getColor() << " " << getName() << "\n\n";
}

void Automobile::addToGarage( Automobile& x )
{
  std::cout << "Adding your car to the garage." << "\n\n";
  garage.push_back( x );
}

void Automobile::showCars( int x ){
  if(garage.size() <= 0){
    std::cout << "You have no automobiles with us. Buy one." << "\n\n";
  }
  else{
    std::cout << "This is what is in your garage: " << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << garage[i].getYear() << " " << garage[i].getColor() << " " << garage[i].getName() << '\n';
    }
    std::cout << '\n';

    bool temp4 = false;
    if (x == 2)
    {
      // I used this showCars() function twice in Exercise1.cpp, this is
      // my way of separating what I want done in those two paths
      temp4 = true;
    }
    while (temp4)
    {
      std::cout << "What would you like to compare?" << '\n'
                << "(1) year, (2) mileage, (3) gas, (4)start date, (5)end date, (6) quit comparing" << '\n'
                << "Enter the number to compare that value from least to highest" << '\n'
                << "Your Choice: ";
      std::cin >> value;
      std::cout << '\n';

      switch(value){
        case 1:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const Automobile &lhs, const Automobile &rhs){
            return lhs.year < rhs.year; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->year << " year model for your automobile called " << it->name << '\n';
          }
          break;

        case 2:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const Automobile &lhs, const Automobile &rhs)
               { return lhs.mileage < rhs.mileage; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->mileage << " miles for your car called " << it->name << '\n';
          }
          break;

        case 3:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const Automobile &lhs, const Automobile &rhs)
               { return lhs.gas < rhs.gas; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->gas << "/10 of a tank full for your car called " << it->name << '\n';
          }
          break;

        case 4:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const Automobile &lhs, const Automobile &rhs)
               { return lhs.startDate < rhs.startDate; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->startDate << " start date year for your car called " << it->name << '\n';
          }
          break;

        case 5:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const Automobile &lhs, const Automobile &rhs)
               { return lhs.endDate < rhs.endDate; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->endDate << " end date year for your car called " << it->name  << '\n';
          }
          break;

        case 6:
          std::cout << "Returning to Main Menu" << '\n';
          temp4 = false;
          break;

        default:
          std::cout << "Please enter a valid number." << "\n\n";
        }
        std::cout << '\n';
    }
  }
}

void Automobile::selectCar(int x){
  std::cout << "Which car would you like to pick out?" << '\n';
  std::cout << "Enter 1 for the first automobile, 2 for the second automobile, 3 for ..." << '\n';
  std::cin >> x;
  std::cout << '\n';
}

void Automobile::generateReport (){

  if (garage.size() <= 0)
  {
    std::cout << "You have no automobiles with us. Buy one." << "\n\n";
  }
  else
  {
    std::cout << "Generating a basic report for your automobiles now. (Printing)" << "\n\n";
    std::cout << "-------------------------------------------" << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << garage[i].getYear() << " "
                << garage[i].getColor() << " "
                << garage[i].getName() << '\n';
      std::cout << garage[i].randomMileage << " miles on the vehicle currently" << '\n'
                << garage[i].randomGasTank << "/10 tank full" << '\n'
                << "The automobiles condition is: " << garage[i].carsHealth << "\n\n";
    }
    std::cout << "-------------------------------------------" << "\n\n";
  }
}

void Automobile::generateReport( bool x ){
  startDateWanted = x;
  if (garage.size() <= 0)
  {
    std::cout << "You have no automobiles with us. Buy one." << "\n\n";
  }
  else
  {
    std::cout << "Generating a report with the first payment start date for your automobile now. (Printing)" << "\n\n";
    std::cout << "-------------------------------------------" << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << "The automobiles's first payment was on the year of " << garage[i].getStartDate() << '\n'
                << garage[i].getYear() << " "
                << garage[i].getColor() << " "
                << garage[i].getName() << '\n';
      std::cout << garage[i].randomMileage << " miles on the vehicle currently" << '\n'
                << garage[i].randomGasTank << "/10 tank full" << '\n'
                << "The automobiles condition is: " << garage[i].carsHealth << "\n\n";
    }
    std::cout << "-------------------------------------------" << "\n\n";
  }
}

void Automobile::generateReport( bool y , bool z ){
  startDateWanted = y;
  endDateWanted = z;
  if (garage.size() <= 0)
  {
    std::cout << "You have no automobiles with us. Buy one." << "\n\n";
  }
  else
  {
    std::cout << "Generating a report with a start date and end date for your automobiles now. (Printing)" << "\n\n";
    std::cout << "-------------------------------------------" << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << "Automobile's first purchased on the year of " << garage[i].getStartDate() << '\n'
                << "The automobiles end of payment date is the year of " << garage[i].getEndDate() << '\n'
                << garage[i].getYear() << " "
                << garage[i].getColor() << " "
                << garage[i].getName() << '\n';
      std::cout << garage[i].randomMileage << " miles on the vehicle currently" << '\n'
                << garage[i].randomGasTank << "/10 tank full" << '\n'
                << "The automobiles condition is: " << garage[i].carsHealth << "\n\n";
    }
    std::cout << "-------------------------------------------" << "\n\n";
  }
}

void Automobile::setFeature( int x ){
  switch( x )
  {
    case 1:
      drive();
      break;
    case 2:
      hover();
      break;
    case 3:
      sail();
      break;
    case 4:
      hide();
      break;
    case 5:
      protect();
      break;
    case 6:
      turnOnAC();
      break;
    case 7:
      windshieldWipers();
      break;
    case 8:
      connectBluetooth();
      break;
    case 9:
      turnOnMediaPlayer();
      break;
    case 10:
      lowerWindows();
      break;
    case 11:
      setPower( 0 );
      break;
    default:
      std::cout << "Please type a number." << '\n';
      break;
  }
}

void Automobile::setPower(int x)
{
  if (x == 1)
  {
    std::cout << "Systems are turning on..." << '\n';
    power = true;
    std::cout << "Systems Engaged." << '\n';
    std::cout << "Hello, Welcome to the Automobile Experience." << "\n\n";
  }
  else if (x == 0)
  {
    std::cout << "Thank you for driving with Automobile." << '\n';
    std::cout << "Systems are shutting down..." << '\n';
    power = false;
    std::cout << "Returning to Main Menu." << "\n\n";
  }
  else
  {
    std::cout << "Error. The car failed to turn on" << "\n\n";
    exit(1);
  }
}

void Automobile::setReport( int x , int y , int z ){
  mileage = x;
  gas = y;

  if( z == 1 ){
    startDate = 2024;
    endDate = 2030;
    carsHealth = "Brand New";
  }
  else if( z == 2 ){
    startDate = 2022;
    endDate = 2027;
    carsHealth = "Used Car";
  }
  else if( z == 3 ){
    startDate = 2021;
    endDate = 2024;
    carsHealth = "Car came from a car accident";
  }
  else if ( z == 4 ){
    startDate = 2020;
    endDate = 2023;
    carsHealth = "Car is literally on fire right now";
  }
  else{
    // default error message
    std::cout << "Error when setting the report." << "\n\n";
    exit(1);
  }
}

int Automobile::getYear(){
  return year;
}

int Automobile::getStartDate(){
  return startDate;
}

int Automobile::getEndDate(){
  return endDate;
}

int Automobile::getMileage(){
  return mileage;
}

int Automobile::getGas(){
  return gas;
}

std::string Automobile::getColor(){
  return color;
}

std::string Automobile::getName(){
  return name;
}

bool Automobile::getPower(){
  return power;
}

void Automobile::drive(){
  std::cout << "Driving Mode Activated" << '\n';
  std::cout << "You may now drive where ever you wish"
            << "\n\n";
}

void Automobile::hover(){
  std::cout << "Hover Mode Activated" << '\n';
  std::cout << "(You feel the wheels tuck into the car, and the jets start" << '\n';
  std::cout << "You are now safely 10 feet above the ground. You may continue to drive now."
            << "\n\n";
}

void Automobile::sail(){
  std::cout << "Sail Mode Activated" << '\n';
  std::cout << "(You feel the wheels tuck into the car, and the back propellor lower)" << '\n';
  std::cout << "You are now safely floating in the water. You may continue to drive now."
            << "\n\n";
}

void Automobile::hide(){
  std::cout << "Hide Mode Activated" << '\n';
  std::cout << "(You notice the car begin to shine and then turn transparent.)" << '\n';
  std::cout << "You are now hidden. No one can see inside or outside of the car. You may continue to drive at your own risk."
            << "\n\n";
}

void Automobile::protect(){
  std::cout << "Protect Mode Activated" << '\n';
  std::cout << "(You notice the a camera light turn on the hood and trunk)" << '\n';
  std::cout << "AI is monitoring your surroundings. It will now move the car away from harm. You may continue to drive."
            << "\n\n";
}

void Automobile::connectBluetooth(){
  std::cout << "Bluetooth Connect Activated" << '\n';
  std::cout << "Your phone is now connected to the Media Player System."
            << "\n\n";
}

void Automobile::turnOnAC(){
  std::cout << "Air Conditioning Activated" << '\n';
  std::cout << "(You feel nice cool hair hit you)" << '\n';
  std::cout << "You may continue to drive now."
            << "\n\n";
}

void Automobile::turnOnMediaPlayer(){
  std::cout << "Media Player Activated" << '\n';
  std::cout << "(Your favorite driving playlist starts playing)"
            << "\n\n";
}

void Automobile::lowerWindows(){
  std::cout << "Power Windows Activated" << '\n';
  std::cout << "(The window lowers, and you feel the fresh air enter the car's cabin.)"
            << "\n\n";
}

void Automobile::windshieldWipers(){
  std::cout << "Windshield Wipers Activated" << '\n';
  std::cout << "(The wiper begins to turn on intervals, brushing the rain away)" << "\n\n";
}
