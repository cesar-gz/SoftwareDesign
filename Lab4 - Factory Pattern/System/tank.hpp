#pragma once

#include <string>

#include "System/Automobile.hpp"

/************************************************************************
** A Concrete Class implementing the concepts of a generic Automobile
**
*************************************************************************/
namespace System
{
  class tank : public Automobile
  {
  public:
    void drive() override;
    void hover() override;
    void sail() override;
    void hide() override;
    void protect() override;
    void fire();

    // Generate a report with zero, 1, or 2 arguments.  The default report period is 1 month prior to today up through today.
    std::string generateReport( std::string start = "No Start Date Added", std::string end = "No End Date Added" ) override;

    virtual ~tank() override;
  };
}
