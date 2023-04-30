#pragma once

namespace Domain::Reservation
{

  class ReservationHandler
  {
    public:
      // Operations
      //   Work in progress ...

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~ReservationHandler() noexcept = 0;


    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      ReservationHandler & operator=( const ReservationHandler & rhs ) = default;    // copy assignment
      ReservationHandler & operator=(       ReservationHandler && rhs )= default;    // move assignment

  };    // class ReservationHandler

} // namespace Domain::Reservation
