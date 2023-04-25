#pragma once

#include <memory>    // unique_ptr
#include <string>
#include <string_view>

/**************************************************************************
** An Abstract Class capturing the concepts of a generic Automobile
**
**************************************************************************/

namespace System
{
  class Automobile
  {
    public:
      // be able to call this function without an object
      static std::unique_ptr<Automobile> placeOrder( std::string_view order );

      // create drive function
      virtual void drive() = 0;
      virtual void hover() = 0;
      virtual void sail() = 0;
      virtual void hide() = 0;
      virtual void protect() = 0;

      // Generate a report with zero, 1, or 2 arguments.
      virtual std::string generateReport(std::string start = "No Start Date Added", std::string end = "No End Date Added") = 0;

      virtual ~Automobile() = 0;

    protected:
      std::string start;
      std::string end;

    private:
  };
}
