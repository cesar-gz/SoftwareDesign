#include <iostream>
#include <memory>

#include "Domain/Reservation/ReservationHandler.hpp"
#include "Domain/Reservation/Reservation.hpp"

namespace Domain::Reservation
{

  int ReservationHandler::filterDateAvailability( int arrival, int departure )
  {
    std::cout << "Inside the Abstract Class Reservation Handler";
    return 1;
  }

  std::unique_ptr<ReservationHandler> ReservationHandler::placeOrder( std::string_view order )
  {
   return std::make_unique<ReservationBase>();
  }

  ReservationHandler::~ReservationHandler() noexcept = default;

} // namespace Domain::Reservation
