#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo> // typeid::name()

#include "System/semiTruck.hpp"

namespace System
{
  // Generate a report with zero, 1, or 2 arguments.
  std::string semiTruck::generateReport( std::string query_start, std::string query_end )
  {
    std::string        baseReport = Automobile::generateReport( query_start, query_end );

    std::ostringstream report;

    report << "Generating specialized semiTruck Report\n"
           << "  Function called:  " << __func__ << " in " << typeid( *this ).name() << '\n'
           << "  Report period:  " << start << " through " << end << "\n\n\n\n";

    std::clog << report.str();
    return baseReport + report.str();    // concatenation
  }

  void semiTruck::drive()
  {
    std::cout << "The truck horn blares, the air bags fill with air, you slowly start driving forward."
              << "\n\n";
  }

  void semiTruck::hover()
  {
    std::cout << "The truck's 18 wheel start to hover, you slowly start driving over traffic."
              << "\n\n";
  }

  void semiTruck::sail()
  {
    std::cout << "The truck begins floating, you start sailing across the ocean."
              << "\n\n";
  }

  void semiTruck::hide()
  {
    std::cout << "The truck turns invisible, you slowly start driving forward."
              << "\n\n";
  }

  void semiTruck::protect()
  {
    std::cout << "The truck horn blares, The AI starts watching traffic around you, then you slowly start driving forward."
              << "\n\n";
  }

  void semiTruck::haul()
  {
    std::cout << "You hook up the truck to the trailer, and starting hauling 40,000 lbs."
              << "\n\n";
  }

  semiTruck::~semiTruck() = default;
}
