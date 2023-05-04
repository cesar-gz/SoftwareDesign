#pragma once

#include "Domain/Account/AccountHandler.hpp"

namespace Domain::Account
{
  class AccountBase : public AccountHandler
  {
  public:
    std::string updateGuestInfo( std::string firstName, std::string lastName ) override;
    int updatePaymentInfo( int creditCardNumber ) override;

    virtual ~AccountBase() override;
  };
}    // namespace Domain::Account
