#include "SemiTruck.hpp"
#include "tank.hpp"
#include <iostream>

static int option;
static int result;
static int theirPick;
static int preference;
int mainMenu();
int getFeature();
int autoChoice();
void setNewFeature(int i);
void setPreference();

// create the user objects
static Automobile client;
static SemiTruck client2;
static tank client3;

int main()
{

  while (true)
  {
    // client chooses from 4 options in the main menu
    option = mainMenu();

    if (option == 1)
    {
      // client decided to buy a automobile
      theirPick = autoChoice();

      if(theirPick == 1){
        // client wanted to buy a basic automobile
        Automobile car{0000, "color", "name"};
        client.addToGarage(car);
      }
      else if(theirPick == 2){
        // client wanted to buy a semi truck
        SemiTruck truck{0000, "color", "name"};
        client.addToGarage(truck);
      }
      else{
        // client wanted to buy a tank
        tank tank{0000, "color", "name"};
        client.addToGarage(tank);
      }
    }
    else if (option == 2)
    {
      // client wants to compare purchased automobile
      client.showCars(option);
    }
    else if (option == 3)
    {
      // client would like to drive a purchased automobile and use the features

      // select a automobile
      client.showCars(option);
      client.selectCar(0);

      setPreference();

      // turn the automobile on
      client.setPower(1);

      // while the automobile is on
      while (client.getPower() == true)
      {
        // ask the client which feature they would like to use,
        // and then use it
        int feature = getFeature();
        setNewFeature(feature);
      }
    }
    else if (option == 4)
    {
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
          std::cout << "Please choose a valid option"
                    << "\n\n";
        }
      }
    }
    else if (option == 5)
    {
      // client would like to end the session
      std::cout << "Thank you for shopping with us. Goodbye."
                << "\n\n";
      break;
    }
    else
    {
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
    std::cout << "Hello customer. What would you like to do today?" << '\n';
    std::cout << "1) Buy an automobile for $250,000" << '\n';
    std::cout << "2) Compare your purchased automobiles" << '\n';
    std::cout << "3) Drive a purchased automobile (Test the Features)" << '\n';
    std::cout << "4) Generate a report for an automobile" << '\n';
    std::cout << "5) Leave the store" << '\n';
    std::cout << "Your choice: ";
    std::cin >> option;
    std::cout << '\n';

    if (option >= 1 && option <= 5)
    {
      return option;
    }
    else
    {
      std::cout << "Please enter 1, 2, 3, 4, or 5." << '\n';
    }
  }
}

int getFeature()
{
  int choice;
  while (true)
  {
    std::cout << "What would you like to do?" << '\n';
    std::cout << "Please enter the appropiate number. "
              << "\n\n";
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
    std::cout << "11) --> * New Feature Unlocked * <--" << '\n';
    std::cout << "12) Turn off automobile" << '\n';
    std::cout << "Your Choice: ";
    std::cin >> choice;
    std::cout << '\n';
    if (choice >= 1 && choice <= 12)
    {
      return choice;
    }
    else
    {
      std::cout << "Please enter a valid number."
                << "\n\n";
    }
  }
}

void setNewFeature(int i)
{
  switch (i)
  {
  case 1:
    if(preference == 1){
      client.drive();
      break;
    }
    else if(preference == 2){
      client2.drive();
      break;
    }
    else{
      client3.drive();
      break;
    }
  case 2:
    if (preference == 1)
    {
      client.hover();
      break;
    }
    else if (preference == 2)
    {
      client2.hover();
      break;
    }
    else
    {
      client3.hover();
      break;
    }
  case 3:
    if (preference == 1)
    {
      client.sail();
      break;
    }
    else if (preference == 2)
    {
      client2.sail();
      break;
    }
    else
    {
      client3.sail();
      break;
    }
  case 4:
    if (preference == 1)
    {
      client.hide();
      break;
    }
    else if (preference == 2)
    {
      client2.hide();
      break;
    }
    else
    {
      client3.hide();
      break;
    }
  case 5:
    if (preference == 1)
    {
      client.protect();
      break;
    }
    else if (preference == 2)
    {
      client2.protect();
      break;
    }
    else
    {
      client3.protect();
      break;
    }
  case 6:
    if (preference == 1)
    {
      client.turnOnAC();
      break;
    }
    else if (preference == 2)
    {
      client2.turnOnAC();
      break;
    }
    else
    {
      client3.turnOnAC();
      break;
    }
  case 7:
    if (preference == 1)
    {
      client.windshieldWipers();
      break;
    }
    else if (preference == 2)
    {
      client2.windshieldWipers();
      break;
    }
    else
    {
      client3.windshieldWipers();
      break;
    }
  case 8:
    if (preference == 1)
    {
      client.connectBluetooth();
      break;
    }
    else if (preference == 2)
    {
      client2.connectBluetooth();
      break;
    }
    else
    {
      client3.connectBluetooth();
      break;
    }
  case 9:
    if (preference == 1)
    {
      client.turnOnMediaPlayer();
      break;
    }
    else if (preference == 2)
    {
      client2.turnOnMediaPlayer();
      break;
    }
    else
    {
      client3.turnOnMediaPlayer();
      break;
    }
  case 10:
    if (preference == 1)
    {
      client.lowerWindows();
      break;
    }
    else if (preference == 2)
    {
      client2.lowerWindows();
      break;
    }
    else
    {
      client3.lowerWindows();
      break;
    }
  case 11:
    if (preference == 2)
    {
      client2.haulLoad();
      break;
    }
    else if (preference == 3)
    {
      client3.fireBazooka();
      break;
    }
    else
    {
      std::cout << "Sorry this is just a base model, no new features."
                << "\n\n";
      break;
    }
  case 12:
    client.setPower(0);
    break;
  default:
    std::cout << "Please type a number." << '\n';
    break;
  }
}

int autoChoice(){
  int pick;
  while(true){
    std::cout << "Would you like a basic automobile, a SemiTruck, or a Tank?"
              << "\n\n";
    std::cout << "Type 1 for an automobile, Type 2 for a SemiTruck, or Type 3 for a Tank"
              << "\n\n";
    std::cin >> pick;
    if(pick >= 1 && pick <= 3){
      return pick;
    }
    std::cout << "Please type a valid number."
              << "\n\n";
  }
}

void setPreference(){
  while(true){
    std::cout << "Is this the automobile, SemiTruck, or Tank?" << '\n';
    std::cout << "Type 1 for auto, Type 2 for semi, Type 3 for tank"
              << "\n\n";
    std::cin >> preference;
    if(preference >= 1 && preference <= 3){
      break;
    }
    std::cout << "Please enter a valid number"
              << "\n\n";
  }
}
