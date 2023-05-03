#include "Domain/Session/Session.hpp"
#include "Domain/Reservation/ReservationHandler.hpp"
#include "Domain/Reservation/Reservation.hpp"

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
  STUB( payFines     )
  STUB( resetAccount )
  STUB( returnBook   )
  STUB( shutdown     )

  std::any checkoutBook( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    // TO-DO  Verify there is such a book and the mark the book as being checked out by user
    std::string results = "Title \"" + args[0] + "\" checkout by \"" + session._credentials.userName + '"';
    session._logger << "checkoutBook:  " + results;
    return { results };
  }

  std::any findRooms( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    /*auto room = Domain::Reservation::ReservationHandler::placeOrder( "ReservationBase" );
    int  firstAvailable = room->filterDateAvailability( 16, 31 );
    std::string results        = "The number is " + std::to_string( firstAvailable ) + args[0];
    session._logger << "findRooms:  " + results;
    return { results }; */
    auto room = Domain::Reservation::ReservationHandler::placeOrder( "ReservationBase" );
    if( room )
    {
      int         firstAvailable = room->filterDateAvailability( 21, 31 );
      std::string results        = "The number is " + std::to_string( firstAvailable );
      session._logger << "findRooms:  " + results;
      return { results };
    }
    else
    {
      session._logger << "findRooms: Error creating room object";
      std::string results = "Error inside findRooms()" + args[0];
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
                         {"Reset Account",   resetAccount},
                         {"Shutdown System", shutdown    } };
  }




  CustomerSession::CustomerSession( const UserCredentials & credentials ) : SessionBase( "Customer", credentials )
  {
    _commandDispatch = { {"Checkout Book", checkoutBook},
                         {"Pay Fines",     payFines    },
                         {"Return Book",   returnBook  },
                         {"Find Rooms",    findRooms   } };
    //{ "Help", help },
  }




  HotelClerkSession::HotelClerkSession( const UserCredentials & credentials ) : SessionBase( "Hotel Clerk", credentials )
  {
    _commandDispatch = { {"Checkout Book", checkoutBook},
                         {"Collect Fines", collectFines},
                         {"Help",          help        },
                         {"Open Archives", openArchives} };
  }




  VendorSession::VendorSession( const UserCredentials & credentials ) : SessionBase( "Vendor", credentials )
  {
    _commandDispatch = { {"Bug People", bugPeople},
                         {"Help",       help} };
  }
}    // namespace Domain::Session
