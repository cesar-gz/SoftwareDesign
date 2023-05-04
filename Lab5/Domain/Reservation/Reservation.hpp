#pragma once

#include "Domain/Reservation/ReservationHandler.hpp"

namespace Domain::Reservation
{
  class ReservationBase : public ReservationHandler
  {
  public:

    int findRoom(int arrival, int departure) override;

    virtual ~ReservationBase() override;
  };
}    // namespace Domain::Reservation
