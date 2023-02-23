#pragma once

#include <string>

#include "Automobile.hpp"

/************************************************************************
** A Concrete Class implementing the concepts of a generic Automobile
**
*************************************************************************/
class semiTruck : public Automobile
{
public:
  void drive() override;
  void hover() override;
  void sail() override;
  void hide() override;
  void protect() override;
  void haul();

  // Generate a report with zero, 1, or 2 arguments.  The default report period is 1 month prior to today up through today.
  std::string generateReport(std::string start = "No Start Date Added", std::string end = "No End Date Added") override;

  virtual ~semiTruck() override;
};
