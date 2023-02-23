#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo> // typeid::name()

#include "tank.hpp"

// Generate a report with zero, 1, or 2 arguments.
std::string tank::generateReport(std::string query_start, std::string query_end)
{
  std::string baseReport = Automobile::generateReport(query_start, query_end);

  std::ostringstream report;

  report << "Generating specialized tank Report\n"
         << "  Function called:  " << __func__ << " in " << typeid(*this).name() << '\n'
         << "  Report period:  " << start << " through " << end << "\n\n\n\n";

  std::clog << report.str();
  return baseReport + report.str(); // concatenation
}

void tank::drive()
{
  std::cout << "The tank horn screams, the tank shakes, you slowly start driving & running over everything."
            << "\n\n";
}

void tank::hover()
{
  std::cout << "The tank magically starts to hover, you slowly start driving over traffic."
            << "\n\n";
}

void tank::sail()
{
  std::cout << "The tank begins floating, you start sailing across the ocean."
            << "\n\n";
}

void tank::hide()
{
  std::cout << "The tank turns invisible, you slowly start driving forward running over everything, discreetly."
            << "\n\n";
}

void tank::protect()
{
  std::cout << "The tank horn blares, The AI starts watching traffic around you, then you slowly start driving forward."
            << "\n\n";
}

void tank::fire()
{
  std::cout << "The tank loads the cannon, takes aim at your target, and fires!"
            << "\n\n";
}

tank::~tank() = default;
