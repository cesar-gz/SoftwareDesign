//definitions file
#include <iostream>
#include <string>
#include <vector>

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
    std::cout << "4) Leave the store" << '\n';
    std::cout << "Your choice: ";
    std::cin >> option;
    std::cout << '\n';

    if( option == 1 || option == 2 || option == 3 || option == 4 )
    {
      return option;
    }
    else
    {
      std::cout << "Please enter 1, 2, 3, or 4." << '\n';
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
    for( int i = 0; i < (int)(garage.size()); i++ )
    {
      std::cout << garage[i].getYear() << " " << garage[i].getColor() << " " << garage[i].getName() << '\n';
    }
  }
}

blackHawk blackHawk::selectCar(int x){
  std::cout << "Which car would you like to pick out?" << '\n';
  std::cout << "Enter 1 for the first car, 2 for the second car, 3 for . . ." << '\n';
  std::cin >> x;

  return garage.at( x );
}

void blackHawk::setActive( bool y ){
  sessionIsActive = y;
}

void blackHawk::setFeature( int x ){
  switch( x )
  {
    case 1:
      std::cout << "Driving Mode Activated" << '\n';
      break;
    case 2:
      std::cout << "Hover Mode Activated" << '\n';
      break;
    case 3:
      std::cout << "Sail Mode Activated" << '\n';
      break;
    case 4:
      std::cout << "Hide Mode Activated" << '\n';
      break;
    case 5:
      std::cout << "Protect Mode Activated" << '\n';
      break;
    case 6:
      std::cout << "Air Conditioning Activated" << '\n';
      break;
    case 7:
      std::cout << "Windshield Wipers Activated" << '\n';
      break;
    case 8:
      std::cout << "Bluetooth Connect Activated" << '\n';
      break;
    case 9:
      std::cout << "Media Player Activated" << '\n';
      break;
    case 10:
      std::cout << "Power Windows Activated" << '\n';
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
  }
  else {
    exit( 1 );
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

