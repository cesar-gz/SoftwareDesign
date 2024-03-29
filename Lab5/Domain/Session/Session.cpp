#include "Domain/Session/Session.hpp"
#include "Domain/Reservation/ReservationHandler.hpp"
#include "Domain/Reservation/Reservation.hpp"
#include "Domain/Account/AccountHandler.hpp"
#include "Domain/Account/Account.hpp"

#include <string>
#include <any>
#include <vector>

namespace  // anonymous (private) working area
{
  // 1)  First define all system events (commands, actions, requests, etc.)
  #define STUB(functionName)  std::any functionName( Domain::Session::SessionBase & /*session*/, const std::vector<std::string> & /*args*/ ) \
                              { return {}; }  // Stubbed for now

  STUB( bugPeople    )
  STUB( collectFines )
  STUB( help         )
  STUB( openArchives )
  STUB( resetAccount )
  STUB( shutdown     )

  int         roomNum;
  std::string Name;
  int         creditCard;
  int         reservationNum;

  std::any findRoom( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    auto room = Domain::Reservation::ReservationHandler::placeOrder( "ReservationBase" );
    if( room )
    {
      roomNum = room->findRoom( 0, 0 );
      std::string results        = "Room " + std::to_string( roomNum ) + " has been added to your Checkout.\n";
      return { results };
    }
    else
    {
      session._logger << "findRooms: Error creating room object";
      std::string results = "Error inside findRoom(), also args[0] causing a seg fault" + args[0];
      return { results };
    }
  }



  std::any updateGuestInfo( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    auto name = Domain::Account::AccountHandler::placeOrder( "AccountBase" );
    if( name )
    {
      Name = name->updateGuestInfo( "first","last" );
      std::string results  = "Success, " + Name + ", your name has been updated and associated with your account.\n ";
      return { results };
    }
    else
    {
      session._logger << "updateGuestInfo: Error creating account object";
      std::string results = "Error inside updateGuestInfo(), also args[0] causing a seg fault" + args[0];
      return { results };
    }
  }




  std::any updatePaymentInfo( Domain::Session::SessionBase & session, const std::vector<std::string> & args ){
    auto number = Domain::Account::AccountHandler::placeOrder( "AccountBase" );
    if( number )
    {
      creditCard = number->updatePaymentInfo( 1 );
      std::string results = "Success, your payment information: " + std::to_string( creditCard ) + ", has been saved for Checkout.\n ";
      return { results };
    }
    else
    {
      session._logger << "updatePaymentInfo: Error creating account object";
      std::string results = "Error inside updatePaymentInfo(), also args[0] causing a seg fault" + args[0];
      return { results };
    }
  }



  std::any createReservation( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    auto resv = Domain::Reservation::ReservationHandler::placeOrder( "ReservationBase" );
    if( resv )
    {
      reservationNum = resv->createReservation( roomNum, Name, creditCard );
      std::string results = "Success your reservation was created. Your reservation number is " + std::to_string( reservationNum ) + ".\n";
      return { results };
    }
    else
    {
      session._logger << "createReservation: Error creating room object";
      std::string results = "Error inside createReservation(), also args[0] causing a seg fault" + args[0];
      return { results };
    }
  }



  std::any searchForReservation( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    auto search = Domain::Reservation::ReservationHandler::placeOrder( "ReservationBase" );
    if( search )
    {
      reservationNum      = search->searchForReservation( Name );
      std::string results = "Success, your reservation number was found and is number " + std::to_string( reservationNum ) + ".\n";
      return { results };
    }
    else
    {
      session._logger << "searchForReservation: Error creating room object";
      std::string results = "Error inside searchForReservation(), also args[0] causing a seg fault" + args[0];
      return { results };
    }
  }

  std::any deleteReservation( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    auto remove = Domain::Reservation::ReservationHandler::placeOrder( "ReservationBase" );
    if( remove )
    {
      reservationNum      = remove->deleteReservation( reservationNum );
      std::string results = "Success, your reservation was deleted.\n";
      return { results };
    }
    else
    {
      session._logger << "deleteReservation: Error creating room object";
      std::string results = "Error inside deleteReservation(), also args[0] causing a seg fault" + args[0];
      return { results };
    }
  }

}    // anonymous (private) working area










namespace Domain::Session
{
  SessionBase::SessionBase( const std::string & description, const UserCredentials & credentials ) : _credentials( credentials ), _name( description )
  {
    _logger << "Session \"" + _name + "\" being used and has been successfully initialized";
  }




  SessionBase::~SessionBase() noexcept
  {
    _logger << "End Session: \"" + _name + "\" shutdown successfully";
  }




  std::vector<std::string> SessionBase::getCommands()
  {
    std::vector<std::string> availableCommands;
    availableCommands.reserve( _commandDispatch.size() );

    for( const auto & [command, function] : _commandDispatch ) availableCommands.emplace_back( command );

    return availableCommands;
  }




  std::any SessionBase::executeCommand( const std::string & command, const std::vector<std::string> & args )
  {
    std::string parameters;
    for( const auto & arg : args )  parameters += '"' + arg + "\"  ";
    _logger << "Responding to \"" + command + "\" request with parameters: " + parameters;

    auto it = _commandDispatch.find( command );
    if( it == _commandDispatch.end() )
    {
      std::string message = __func__;
      message += " attempt to execute \"" + command + "\" failed, no such command";

      _logger << message;
      throw BadCommand( message );
    }

    auto results = it->second( *this, args);

    if( results.has_value() )
    {
      // The type of result depends on function called.  Let's assume strings for now ...
      _logger << "Responding with: \"" + std::any_cast<const std::string &>( results ) + '"';
    }

    return results;
  }








  // 2) Now map the above system events to roles authorized to make such a request.  Many roles can request the same event, and many
  //    events can be requested by a single role.
  SystemAdministratorSession::SystemAdministratorSession( const UserCredentials & credentials ) : SessionBase( "System Administrator", credentials )
  {
    _commandDispatch = { {"Help",            help        },
                         {"Open Archives",   openArchives},
                         {"Reset Account",   resetAccount},
                         {"Shutdown System", shutdown    } };
  }




  CustomerSession::CustomerSession( const UserCredentials & credentials ) : SessionBase( "Customer", credentials )
  {
    _commandDispatch = { { "Find Room",              findRoom               },
                         { "Update Guest Info",      updateGuestInfo        },
                         { "Update Payment Info",    updatePaymentInfo      },
                         { "Create Reservation",     createReservation      },
                         { "Search for Reservation", searchForReservation   },
                         { "Delete Reservation",     deleteReservation      } };
  }




  HotelClerkSession::HotelClerkSession( const UserCredentials & credentials ) : SessionBase( "Hotel Clerk", credentials )
  {
    _commandDispatch = { { "Find Room",              findRoom               },
                         { "Collect Fines",          collectFines           },
                         { "Help",                   help                   },
                         { "Make Reservation",       createReservation      },
                         { "Search for Reservation", searchForReservation   },
                         { "Delete Reservation",     deleteReservation      } };
  }




  VendorSession::VendorSession( const UserCredentials & credentials ) : SessionBase( "Vendor", credentials )
  {
    _commandDispatch = { {"Bug People", bugPeople},
                         {"Help",       help} };
  }
}    // namespace Domain::Session
