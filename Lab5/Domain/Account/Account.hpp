#pragma once

#include "Domain/Account/AccountHandler.hpp"

namespace Domain::Account
{
  class AccountBase : public AccountHandler
  {
  public:
    std::string updateGuestInfo( std::string firstName, std::string lastName ) override;

    virtual ~AccountBase() override;
  };
}    // namespace Domain::Account
