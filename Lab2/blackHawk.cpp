//definitions file
#include <iostream>

#include "blackHawk.hpp"

// blackHawk constructor
blackHawk::blackHawk( int year, int month, int day )
{
  SetDate( year, month, day );
}

// blackHawk member functions
void blackHawk::SetDate( int year, int month, int day )
{
  m_month = month;
  m_day   = day;
  m_year  = year;
}

void blackHawk::printDate( blackHawk& date )
{
  std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

int blackHawk::getYear()
{
  return m_year;
}

int blackHawk::getMonth()
{
  return m_month;
}

int blackHawk::getDay()
{
  return m_day;
}
