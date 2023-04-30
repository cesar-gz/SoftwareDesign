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

      virtual int filterDateAvailability( int arrival, int departure ) = 0;

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~ReservationHandler() noexcept = 0;

    protected:
      int arrival;
      int departure;
      int reservationNumber;
      std::vector<int> roomsAvailable;

      // Copy assignment operators, protected to prevent mix derived-type assignments
      ReservationHandler & operator=( const ReservationHandler & rhs ) = default;    // copy assignment
      ReservationHandler & operator=( ReservationHandler && rhs )      = default;    // move assignment

  };    // class ReservationHandler

} // namespace Domain::Reservation
