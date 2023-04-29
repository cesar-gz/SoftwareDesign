#include <iostream>
#include <locale>       // touuper(), locale()

#include "UI/UserInterfaceHandler.hpp"

int main( /*int argc, char argv[] */ )
{
    std::cout << "\nHotel-Easy Reservation system initializing ...\n\n";

    // Smart pointer (for proper, exception safe memory management) to interface set to new instance of a configurable
    // implementation of the interface.
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
