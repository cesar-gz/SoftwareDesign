#include <iostream>
#include <vector>

#include "Domain/Reservation/Reservation.hpp"

namespace Domain::Reservation
{

  ReservationBase::ReservationBase(){}

  int ReservationBase::filterDateAvailability( int arrival, int departure )
  {
    std::vector<int> rooms;
    int              lengthOfStay = departure - arrival;

    if( lengthOfStay > 10 )
    {
      for( int i = 0; i < 5; i++ )
      {
        rooms.push_back( roomsAvailable[i] );
      }

      std::cout << "Rooms Available: ";
      for( int i = 0; i < rooms.size(); i++ )
      {
        std::cout << rooms[i] << " ";
      }
      std::cout << std::endl;

      // return the first available room in the list
      return rooms[0];
    }
    else
    {
      for( int i = 14; i < 20; i++ )
      {
        rooms.push_back( roomsAvailable[i] );
      }

      std::cout << "Rooms Available: ";
      for( int i = 0; i < rooms.size(); i++ )
      {
        std::cout << rooms[i] << " ";
      }
      std::cout << std::endl;

      // return the first available room in the list
      return rooms[0];
    }
  }

  ReservationBase::~ReservationBase() noexcept {}

}    // namespace Domain::Reservation
