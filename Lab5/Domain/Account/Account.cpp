#include <iostream>
#include <vector>

#include "Domain/Account/Account.hpp"

namespace Domain::Account
{

  std::string AccountBase::updateGuestInfo( std::string first_Name, std::string last_Name )
  {

    std::cout << "First Name:" << " ";
    std::cin >> first_Name;
    std::cout << "Last Name:" << " ";
    std::cin >> last_Name;

    // save for later
    fullName = first_Name + " " + last_Name;

    return fullName;
  }

  int AccountBase::updatePaymentInfo( int creditCard_Number){
    std::cout << "Credit Card Number:" << " ";
    std::cin >> creditCard_Number;

    std::string str    = std::to_string( creditCard_Number );
    int         length = static_cast<int>( str.length() );


    if( length == 9 )
    {
      // save for later
      creditCardNumber = creditCard_Number;
      return creditCardNumber;
    }
    else{
      std::cout << "Invalid Credit Card Number. Please Enter a valid Credit Card Number.\n" << " ";
      return 0;
    }
  }

  AccountBase::~AccountBase() = default;

}    // namespace Domain::Account
