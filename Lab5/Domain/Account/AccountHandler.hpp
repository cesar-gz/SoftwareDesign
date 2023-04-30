#pragma once

namespace Domain::Account
{

  class AccountHandler
  {
    public:
      // Operations
      //   Work in progress ...

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~AccountHandler() noexcept = 0;


    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      AccountHandler & operator=( const AccountHandler & rhs ) = default;    // copy assignment
      AccountHandler & operator=(       AccountHandler && rhs )= default;    // move assignment


  };    // class AccountHandler

} // namespace Domain::Account
