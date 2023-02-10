#include "Automobile.hpp"
#include <iostream>

static int option;
static int result;
int mainMenu();
int getFeature();

int main(){
  // create the user object
  Automobile client{};

  while( true ){
    // client chooses from 4 options in the main menu
    option = mainMenu();

    if( option == 1 ){
      // client decided to buy a car
      Automobile car{0000, "color", "name"};
      client.addToGarage( car );
    }
    else if( option == 2 ){
      // client wants to compare purchased cars
      client.showCars(option);
    }
    else if( option == 3 ){
      // client would like to drive a purchased car and use the features

      // select a car
      client.showCars(option);
      client.selectCar(0);

      // turn the car on
      client.setPower( 1 );

      // while the car is on
      while( client.getPower() == true )
      {
        // ask client which feature they would like to use,
        // and then use it
        int feature = getFeature();
        client.setFeature(feature);
      }
    }
    else if( option == 4 ){
      // client has asked to generate a report
      while (true)
      {
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
          client.generateReport();
          break;
        }
        else if (result == 2)
        {
          client.generateReport(true);
          break;
        }
        else if (result == 3)
        {
          client.generateReport(true, true);
          break;
        }
        else
        {
          std::cout << "Please choose a valid option" << "\n\n";
        }
      }

    }
    else if( option == 5 ){
      // client would like to end the session
      std::cout << "Thank you for shopping with us. Goodbye." << "\n\n";
      break;
    }
    else{
      // default error message
      std::cout << "Error." << '\n';
      exit(1);
    }
  }
  return 0;
}


/* Interface Function definitions */
int mainMenu()
{
  while (true)
  {
    std::cout << "Hello client. What would you like to do today?" << '\n';
    std::cout << "1) Buy a Automobile car for $250,000" << '\n';
    std::cout << "2) Compare my purchased cars" << '\n';
    std::cout << "3) Drive a purchased car (Test the Features)" << '\n';
    std::cout << "4) Generate a report for a car" << '\n';
    std::cout << "5) Leave the store" << '\n';
    std::cout << "Your choice: ";
    std::cin >> option;
    std::cout << '\n';

    if (option >= 1 && option <= 5) { return option; }
    else { std::cout << "Please enter 1, 2, 3, 4, or 5." << '\n'; }
  }
}

int getFeature()
{
  int choice;
  while(true){
    std::cout << "What would you like to do?" << '\n';
    std::cout << "Please enter the appropiate number. " << "\n\n";
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
    std::cin >> choice;
    std::cout << '\n';
    if(choice >= 1 && choice <= 11){ return choice; }
    else{std::cout << "Please enter a valid number." << "\n\n";}
  }
}
