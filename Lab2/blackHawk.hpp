// declaration file

#pragma once

class blackHawk{
  private:
    int m_year {};
    int m_month {};
    int m_day {};

  public:
    blackHawk( int year, int month, int day );

    void SetDate( int year, int month, int day );
    void printDate( blackHawk& date );

    int  getYear();
    int  getMonth();
    int  getDay();
};
