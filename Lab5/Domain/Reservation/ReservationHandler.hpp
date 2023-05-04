#pragma once

#include <any>
#include <memory>    // unique_ptr
#include <string>
#include <string_view>
#include <vector>

namespace Domain::Reservation
{

  class ReservationHandler
  {
    public:
      static std::unique_ptr<ReservationHandler> placeOrder( std::string_view order );

      virtual int findRoom( int arrival, int departure ) = 0;

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~ReservationHandler() = 0;

    protected:
      int arrival;
      int departure;
      int roomNumber;
      int reservationNumber;
      std::vector<int> roomsAvailable = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

      // Copy assignment operators, protected to prevent mix derived-type assignments
      ReservationHandler & operator=( const ReservationHandler & rhs ) = default;    // copy assignment
      ReservationHandler & operator=( ReservationHandler && rhs )      = default;    // move assignment

  };    // class ReservationHandler

} // namespace Domain::Reservation
