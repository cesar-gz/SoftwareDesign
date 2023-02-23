#pragma once

#include <string>

/**************************************************************************
** An Abstract Class capturing the concepts of a generic Automobile
**
**************************************************************************/
class Automobile
{
public:

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
