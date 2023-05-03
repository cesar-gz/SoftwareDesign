#include <iostream>
#include <locale>       // touuper(), locale()

#include "UI/UserInterfaceHandler.hpp"

int main()
{
    std::cout << "\nHotel-Easy Reservation system initializing ...\n\n";

    auto userInterface = UI::UserInterfaceHandler::createUI();

    std::cout << "\nInitialization completed successfully\n";

    char response;
    do
    {
      std::cout << "Ready to transition into Operational State? (Y/N) ";
      std::cin >> response;
      response = std::toupper( response, std::locale() );
    } while( response != 'Y' );

    if( response == 'Y' ) userInterface->launch();


    std::cout << "\nProgram complete, initiating shutdown\n";
  }
