#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <typeinfo>    // typeid::name()

#include "System/Automobile.hpp"
#include "System/semiTruck.hpp"
#include "System/tank.hpp"

namespace System
{

  /***************************************************
  ** Factory Function
  ****************************************************/
  std::unique_ptr<Automobile> Automobile::placeOrder( std::string_view order )
  {
    if( order == "semiTruck" ) return std::make_unique<semiTruck>();
    if( order == "tank" ) return std::make_unique<tank>();

    throw std::range_error( "Request to create an unknown automobile type:  " + std::string{ order } );
  }

  // Generate a report with zero, 1, or 2 arguments.  Need to fix the actual code inside function
  std::string Automobile::generateReport( std::string query_start, std::string query_end )
  {
    std::ostringstream report;

    report << "Generating generic Automobile Report\n"
           << "  Function called:  " << __func__ << " in " << typeid( *this ).name() << '\n'
           << "  Report period:  " << query_start << " through " << query_end << "\n\n";

    std::clog << report.str();
    return report.str();
  }

  void Automobile::drive()
  {
    std::cout << "The car engine start and you start your car to work."
              << "\n\n";
  }

  void Automobile::hover()
  {
    std::cout << "You start the car's hover mode, and start hovering over traffic."
              << "\n\n";
  }

  void Automobile::sail()
  {
    std::cout << "You start the car's sail mode, and start boating across the ocean."
              << "\n\n";
  }

  void Automobile::hide()
  {
    std::cout << "You start the car's hide mode, and the car turns invisible."
              << "\n\n";
  }

  void Automobile::protect()
  {
    std::cout << "You start the car's protect mode, and AI starts watching traffic around your car."
              << "\n\n";
  }

  Automobile::~Automobile() = default;
}
