//definitions file
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> // for generating random numbers for setReport()

#include "blackHawk.hpp"

// blackHawk constructor
blackHawk::blackHawk(){}

blackHawk::blackHawk(int Year, std::string Color, std::string Name){
  customizeCar( Year, Color, Name );
}

// blackHawk member functions
int blackHawk::mainMenu()
{
  while(true){
    std::cout << "Hello client. What would you like to do today?" << '\n';
    std::cout << "1) Buy a BlackHawk car for $250,000" << '\n';
    std::cout << "2) Compare my purchased cars" << '\n';
    std::cout << "3) Drive a purchased car (Test the Features)" << '\n';
    std::cout << "4) Generate a report for a car" << '\n';
    std::cout << "5) Leave the store" << '\n';
    std::cout << "Your choice: ";
    std::cin >> option;
    std::cout << '\n';

    if( option == 1 || option == 2 || option == 3 || option == 4 || option == 5 )
    {
      return option;
    }
    else
    {
      std::cout << "Please enter 1, 2, 3, 4, or 5." << '\n';
    }
  }
}

void blackHawk::customizeCar(int Year, std::string Color, std::string Name){
  while(true){
    std::cout << "We have the new 2023, last years 2022 model, and the original 2021." << '\n';
    std::cout << "What year model would you like?" << '\n';
    std::cout << "Type 2023, 2022, or 2021: ";
    std::cin >> Year;
    std::cout << '\n';

    if ( Year == 2023 || Year == 2022 || Year == 2021){
      break;
    }
    std::cout << "Please choose one of the options." << '\n';
    std::cout << '\n';
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
    std::cout << "Please choose one of the options." << '\n';
    std::cout << '\n';
  }

  std::cout << "What would you like to name your car?" << '\n';
  std::cin >> Name;
  std::cout << '\n';

  year = Year;
  color = Color;
  name  = Name;

  srand(static_cast<unsigned>(time(NULL)));
  randomMileage = rand() % 250000; // generate mileage from 0-250,000
  srand(static_cast<unsigned>(time(NULL)));
  randomGasTank = 1 + rand() % 10;  // generate gas tank size from 1/10 to 10/10
  srand(static_cast<unsigned>(time(NULL)));
  randomCondition = 1 + rand() % 4; // generate random condition from 1 to 4
  setReport(randomMileage, randomGasTank, randomCondition);

  std::cout << "Congratulations, you are the owner of a " << '\n';
  std::cout << getYear() << " " << getColor() << " " << getName() << '\n';
  std::cout << '\n';

  setPurchase( 1 );
}


void blackHawk::addToGarage( blackHawk x )
{
  std::cout << "Adding your car to the garage." << '\n';
  garage.push_back( x );
  std::cout << '\n';
}

void blackHawk::showCars(){
  if(garage.size() <= 0){
    std::cout << "You have no cars with us. Buy one." << '\n';
    std::cout << '\n';
  }
  else{
    std::cout << "This is what is in your garage: " << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << garage[i].getYear() << " " << garage[i].getColor() << " " << garage[i].getName() << '\n';
    }
    std::cout << '\n';

    bool temp4 = false;
    if (option == 2)
    {
      // I used this showCars() function twice in Exercise1.cpp, this is
      // my way of separating what I want done in those two instances
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
          sort(garage.begin(), garage.end(), [](const blackHawk &lhs, const blackHawk &rhs){
            return lhs.year < rhs.year; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->year << " year model for your car called " << it->name << '\n';
          }
          break;
        case 2:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const blackHawk &lhs, const blackHawk &rhs)
               { return lhs.mileage < rhs.mileage; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->mileage << " miles for your car called " << it->name << '\n';
          }
          break;
        case 3:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const blackHawk &lhs, const blackHawk &rhs)
               { return lhs.gas < rhs.gas; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->gas << "/10 of a tank full for your car called " << it->name << '\n';
          }
          break;
        case 4:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const blackHawk &lhs, const blackHawk &rhs)
               { return lhs.startDate < rhs.startDate; });
          for (auto it = garage.begin(); it != garage.end(); it++)
          {
            std::cout << it->startDate << " start date year for your car called " << it->name << '\n';
          }
          break;
        case 5:
          std::cout << "The list of values sorted:" << '\n';
          sort(garage.begin(), garage.end(), [](const blackHawk &lhs, const blackHawk &rhs)
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
          std::cout << "Please enter a valid value." << '\n';
          std::cout << '\n';
        }
        std::cout << '\n';
    }
  }
}

blackHawk blackHawk::selectCar(int x){
  std::cout << "Which car would you like to pick out?" << '\n';
  std::cout << "Enter 1 for the first car, 2 for the second car, 3 for ..." << '\n';
  std::cin >> x;
  std::cout << '\n';

  return garage.at( x-1 );
}

void blackHawk::queryClient(){
  while(true){
    std::cout << "(A) Would you like a report without the start date and end date of the purchase/lease?" << '\n'
              << "(B) A report with just the start date of purchase/lease?" << '\n'
              << "(C) Or a report just the start date and end date of the purchase/lease?" << '\n';
    std::cout << "Enter 1 for option A" << '\n'
              << "Enter 2 for option B" << '\n'
              << "Enter 3 for option C" << '\n';
    std::cin >> result;
    std::cout << '\n';

    if (result == 1)
    {
      generateReport();
      break;
    }
    else if (result == 2)
    {
      generateReport( true );
      break;
    }
    else if (result == 3)
    {
      generateReport( true, true );
      break;
    }
    else{
      std::cout << "Please choose a valid option" << '\n';
      std::cout << '\n';
    }
  }
}

void blackHawk::generateReport (){

  if (garage.size() <= 0)
  {
    std::cout << "You have no cars with us. Buy one." << '\n';
    std::cout << '\n';
  }
  else
  {
    std::cout << "Generating a full report for your cars now. (Printing)" << '\n';
    std::cout << '\n';
    std::cout << "-------------------------------------------" << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << garage[i].getYear() << " "
                << garage[i].getColor() << " "
                << garage[i].getName() << '\n';
      std::cout << garage[i].randomMileage << " miles on the vehicle currently" << '\n'
                << garage[i].randomGasTank << "/10 tank full" << '\n'
                << "The cars condition is: " << garage[i].carsHealth << '\n';
      std::cout << '\n';
    }
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';
  }
}

void blackHawk::generateReport( bool x ){
  startDateWanted = x;
  if (garage.size() <= 0)
  {
    std::cout << "You have no cars with us. Buy one." << '\n';
    std::cout << '\n';
  }
  else
  {
    std::cout << "Generating a report with a start date for your cars now. (Printing)" << '\n';
    std::cout << '\n';
    std::cout << "-------------------------------------------" << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << "Car first purchased on the year of " << garage[i].getStartDate() << '\n'
                << garage[i].getYear() << " "
                << garage[i].getColor() << " "
                << garage[i].getName() << '\n';
      std::cout << garage[i].randomMileage << " miles on the vehicle currently" << '\n'
                << garage[i].randomGasTank << "/10 tank full" << '\n'
                << "The cars condition is: " << garage[i].carsHealth << '\n';
      std::cout << '\n';
    }
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';
  }
}

void blackHawk::generateReport( bool y , bool z ){
  startDateWanted = y;
  endDateWanted = z;
  if (garage.size() <= 0)
  {
    std::cout << "You have no cars with us. Buy one." << '\n';
    std::cout << '\n';
  }
  else
  {
    std::cout << "Generating a report with a start date and end date for your cars now. (Printing)" << '\n';
    std::cout << '\n';
    std::cout << "-------------------------------------------" << '\n';
    for (int i = 0; i < static_cast<int>(garage.size()); i++)
    {
      std::cout << "Car first purchased on the year of " << garage[i].getStartDate() << '\n'
                << "The Cars end of payment date is the year of " << garage[i].getEndDate() << '\n'
                << garage[i].getYear() << " "
                << garage[i].getColor() << " "
                << garage[i].getName() << '\n';
      std::cout << garage[i].randomMileage << " miles on the vehicle currently" << '\n'
                << garage[i].randomGasTank << "/10 tank full" << '\n'
                << "The cars condition is: " << garage[i].carsHealth << '\n';
      std::cout << '\n';
    }
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';
  }
}

void blackHawk::setActive( bool y ){
  sessionIsActive = y;
}

void blackHawk::setFeature( int x ){
  switch( x )
  {
    case 1:
      std::cout << "Driving Mode Activated" << '\n';
      std::cout << "You may now drive where ever you wish" << '\n';
      break;
    case 2:
      std::cout << "Hover Mode Activated" << '\n';
      std::cout << "(You feel the wheels tuck into the car, and the jets start" << '\n';
      std::cout << "You are now safely 10 feet above the ground. You may continue to drive now."
                << "\n";
      break;
    case 3:
      std::cout << "Sail Mode Activated" << '\n';
      std::cout << "(You feel the wheels tuck into the car, and the back propellor lower)" << '\n';
      std::cout << "You are now safely floating in the water. You may continue to drive now." << '\n';
      break;
    case 4:
      std::cout << "Hide Mode Activated" << '\n';
      std::cout << "(You notice the car begin to shine and then turn transparent.)" << '\n';
      std::cout << "You are now hidden. No one can see inside or outside of the car. You may continue to drive at your own risk." << '\n';
      break;
    case 5:
      std::cout << "Protect Mode Activated" << '\n';
      std::cout << "(You notice the a camera light turn on the hood and trunk)" << '\n';
      std::cout << "AI is monitoring your surroundings. It will now move the car away from harm. You may continue to drive." << '\n';
      break;
    case 6:
      std::cout << "Air Conditioning Activated" << '\n';
      std::cout << "(You feel nice cool hair hit you)" << '\n';
      std::cout << "You may continue to drive now." << '\n';
      break;
    case 7:
      std::cout << "Windshield Wipers Activated" << '\n';
      std::cout << "(The wiper begins to turn on intervals, brushing the rain away)" << '\n';
      break;
    case 8:
      std::cout << "Bluetooth Connect Activated" << '\n';
      std::cout << "Your phone is now connected to the Media Player System." << '\n';
      break;
    case 9:
      std::cout << "Media Player Activated" << '\n';
      std::cout << "(Your favorite driving playlist starts playing)" << '\n';
      break;
    case 10:
      std::cout << "Power Windows Activated" << '\n';
      std::cout << "(The window lowers, and you feel the fresh air enter the car's cabin.)" << '\n';
      break;
    case 11:
      setPower( 0 );
      break;
    default:
      std::cout << "Please type a number." << '\n';
      break;
  }
}

void blackHawk::setPurchase(int x){
  if ( x == 0){
    purchase = 0;
  }
  else if ( x == 1 ){
    purchase += 1;
    std::cout << "Thank you for your purchase." << '\n';
  }
  else{
    std::cout << "Error." << '\n';
    exit( 1 );
  }
}

void blackHawk::setPower(int x){
  if( x == 1 ){
    std::cout << "Systems are turning on..." << '\n';
    power = true;
    std::cout << "Systems Engaged." << '\n';
    std::cout << "Hello, Welcome to the BlackHawk Experience." << '\n' << '\n';
  }
  else if ( x == 0){
    std::cout << "Thank you for driving with BlackHawk." << '\n';
    std::cout << "Systems are shutting down..." << '\n';
    power = false;
    std::cout << "Returning to Main Menu." << '\n';
    std::cout << '\n';
  }
  else {
    std::cout << "Thank you for shopping with us at BlackHawk Inc." << '\n';
    std::cout << "Goodbye." << '\n';
    std::cout << '\n';
    exit(1);
  }
}

void blackHawk::setReport( int x , int y , int z ){
  mileage = x;
  gas = y;

  if( z == 1 ){
    startDate = 2023;
    endDate = 2030;
    carsHealth = "Brand New";
  }
  else if( z == 2 ){
    startDate = 2023;
    endDate = 2027;
    carsHealth = "Used Car";
  }
  else if( z == 3 ){
    startDate = 2023;
    endDate = 2024;
    carsHealth = "Car came from a car accident";
  }
  else if ( z == 4 ){
    startDate = 2023;
    endDate = 2023;
    carsHealth = "Car is literally on fire right now";
  }
  else{
    // default error message
    setPurchase(-1);
  }
}

int  blackHawk::getFeature(){
  std::cout << "What would you like to do?" << '\n';
  std::cout << "Please enter the appropiate number. " << '\n';
  std::cout << " " << '\n';
  std::cout << "1) Drive Mode" << '\n';
  std::cout << "2) Hover Mode" << '\n';
  std::cout << "3) Sail Mode" << '\n';
  std::cout << "4) Hide Mode" << '\n';
  std::cout << "5) Protect Mode" << '\n';
  std::cout << "6) Air Conditioning" << '\n';
  std::cout << "7) Windshield Wipers" << '\n';
  std::cout << "8) Bluetooth Connect" << '\n';
  std::cout << "9) Media Player" << '\n';
  std::cout << "10) Power Windows" << '\n';
  std::cout << "11) Turn off car" << '\n';
  std::cout << "Your Choice: ";
  std::cin >> feature;
  std::cout << '\n';
  return feature;
}

int blackHawk::getYear(){
  return year;
}

int blackHawk::getStartDate(){
  return startDate;
}

int blackHawk::getEndDate(){
  return endDate;
}

int blackHawk::getMileage(){
  return mileage;
}

int blackHawk::getGas(){
  return gas;
}

std::string blackHawk::getColor(){
  return color;
}

std::string blackHawk::getName(){
  return name;
}

bool blackHawk::getActive(){
  return sessionIsActive;
}

bool blackHawk::getPower(){
  return power;
}

bool blackHawk::getPurchase(){
  return purchase;
}
