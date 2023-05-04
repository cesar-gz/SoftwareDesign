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

  AccountBase::~AccountBase() = default;

}    // namespace Domain::Account
