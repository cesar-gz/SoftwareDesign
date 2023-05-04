#include <iostream>
#include <vector>

#include "Domain/Reservation/Reservation.hpp"

namespace Domain::Reservation
{

  int ReservationBase::findRoom( int arrival_day, int departure_day )
  {
    std::vector<int> rooms(0,0);

    std::cout << "Arrival Day:" << " ";
    std::cin >> arrival_day;
    std::cout << "Departure Day:" << " ";
    std::cin >> departure_day;

    int lengthOfStay = departure_day - arrival_day;

    if( lengthOfStay > 10 )
    {
      for( std::size_t i = 0; i < 5; i++ )
        { rooms.push_back( roomsAvailable[i] ); }

      std::cout << "Available Rooms Include: ";
      for( std::size_t i = 0; i < rooms.size(); i++ )
        { std::cout << "\nRoom " << rooms[i] << " "; }

      // save for later
      roomNumber = rooms[0];
      // return the first available room in the list
      return rooms[0];
    }
    else
    {
      for( std::size_t i = 14; i < 20; i++ )
        { rooms.push_back( roomsAvailable[i] ); }

      std::cout << "\nAvailable Rooms Include: ";

      for( std::size_t i = 0; i < rooms.size(); i++ )
        { std::cout << "\nRoom " << rooms[i] << " "; }

      // save for later
      roomNumber = rooms[0];
      // return the first available room in the list
      return rooms[0];
    }
  }

  ReservationBase::~ReservationBase() = default;

}    // namespace Domain::Reservation
