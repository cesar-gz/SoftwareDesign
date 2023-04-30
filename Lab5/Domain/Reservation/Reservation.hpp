#pragma once

#include "Domain/Reservation/ReservationHandler.hpp"

namespace Domain::Reservation
{
  class ReservationBase : public ReservationHandler
  {
  public:
    ReservationBase();

    int filterDateAvailability(int arrival, int departure) override;

    ~ReservationBase() noexcept override = 0;
  };
}    // namespace Domain::Reservation
