#include <iostream>
#include <vector>

#include "Domain/Reservation/Reservation.hpp"

namespace Domain::Reservation
{

  int ReservationBase::filterDateAvailability( int arrival_day, int departure_day )
  {
    std::vector<int> rooms(0,0);
    int              lengthOfStay = departure_day - arrival_day;

    if( lengthOfStay > 10 )
    {
      for( std::size_t i = 0; i < 5; i++ )
        {
          rooms.push_back( roomsAvailable[i] );
        }

      std::cout << "Rooms Available: ";
      for( std::size_t i = 0; i < rooms.size(); i++ )
        {
          std::cout << rooms[i] << " ";
        }
      std::cout << std::endl;

      // return the first available room in the list
      return rooms[0];
    }
    else
    {
      for( std::size_t i = 14; i < 20; i++ )
        {
          rooms.push_back( roomsAvailable[i] );
        }

      std::cout << "Rooms Available: ";
      for( std::size_t i = 0; i < rooms.size(); i++ )
        {
          std::cout << rooms[i] << " ";
        }
      std::cout << std::endl;

      // return the first available room in the list
      return rooms[0];
    }
  }

  ReservationBase::~ReservationBase() = default;

}    // namespace Domain::Reservation
