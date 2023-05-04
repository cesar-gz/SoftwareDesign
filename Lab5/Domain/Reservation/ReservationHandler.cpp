#include <iostream>
#include <memory>

#include "Domain/Reservation/ReservationHandler.hpp"
#include "Domain/Reservation/Reservation.hpp"

namespace Domain::Reservation
{

  int ReservationHandler::findRoom( int arrival_day, int departure_day )
  {
    int difference = arrival_day - departure_day;
    return difference;
  }

  int ReservationHandler::createReservation( int room_Num, std::string Guest_Name, int credit_Card )
  {
    int notImportant = credit_Card - room_Num;
    std::string unImportant  = Guest_Name;
    return notImportant;
  }

      std::unique_ptr<ReservationHandler> ReservationHandler::placeOrder( std::string_view order )
  {
    if( order == "ReservationBase" ) return std::make_unique<ReservationBase>();
    throw std::range_error( "Request to create an unknown class type:  " + std::string{ order } );

  }

  ReservationHandler::~ReservationHandler() = default;

} // namespace Domain::Reservation
