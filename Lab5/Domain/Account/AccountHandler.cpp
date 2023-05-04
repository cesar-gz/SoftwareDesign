#include <iostream>
#include <memory>

#include "Domain/Account/AccountHandler.hpp"
#include "Domain/Account/Account.hpp"

namespace Domain::Account
{

  std::string AccountHandler::updateGuestInfo( std::string first_Name, std::string last_Name )
  {
    fullName = first_Name + last_Name;
    return fullName;
  }

  std::unique_ptr<AccountHandler> AccountHandler::placeOrder( std::string_view order )
  {
    if( order == "AccountBase" ) return std::make_unique<AccountBase>();
    throw std::range_error( "Request to create an unknown class type:  " + std::string{ order } );

  }

  AccountHandler::~AccountHandler() = default;

} // namespace Domain::Account
