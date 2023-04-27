#pragma once

#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::Reservation
{
  // Import the User Credentials type from the lower layer and publish it as your own
  using TechnicalServices::Persistence::UserCredentials;


  // Library Package within the Domain Layer Abstract class
  // The SessionHandler abstract class serves as the generalization of all user commands
  class ReservationHandler
  {
    public:
      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~ReservationHandler() noexcept = 0;


    protected:

  };    // class ReservationHandler
} // namespace Domain::Reservation