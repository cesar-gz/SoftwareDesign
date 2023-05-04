#pragma once

#include <any>
#include <memory>    // unique_ptr
#include <string>
#include <string_view>
#include <vector>

namespace Domain::Account
{

  class AccountHandler
  {
  public:
    static std::unique_ptr<AccountHandler> placeOrder( std::string_view order );

    virtual std::string updateGuestInfo( std::string firstName, std::string lastName ) = 0;
    virtual int updatePaymentInfo( int creditCardNumber ) = 0;

    // Destructor
    // Pure virtual destructor helps force the class to be abstract, but must still be implemented
    virtual ~AccountHandler() = 0;

  protected:
    std::string firstName;
    std::string lastName;
    std::string fullName;
    int         creditCardNumber;

    // Copy assignment operators, protected to prevent mix derived-type assignments
    AccountHandler & operator=( const AccountHandler & rhs ) = default;    // copy assignment
    AccountHandler & operator=( AccountHandler && rhs )      = default;    // move assignment

  };    // class AccountHandler

}    // namespace Domain::Account
