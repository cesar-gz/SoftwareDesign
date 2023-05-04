#include <iostream>
#include <vector>

#include "Domain/Reservation/Reservation.hpp"
#include "Domain/Account/Account.hpp"

namespace Domain::Reservation
{

  int ReservationBase::findRoom( int arrival_day, int departure_day )
  {
    std::vector<int> rooms(0,0);

    std::cout << "Arrival Day:" << " ";
    std::cin >> arrival_day;
    std::cout << "Departure Day:" << " ";
    std::cin >> departure_day;

    int lengthOfStay = departure_day - arrival_day;

    if( lengthOfStay > 10 )
    {
      for( std::size_t i = 0; i < 5; i++ )
        { rooms.push_back( roomsAvailable[i] ); }

      std::cout << "Available Rooms Include: ";
      for( std::size_t i = 0; i < rooms.size(); i++ )
        { std::cout << "\nRoom " << rooms[i] << " "; }

      // save for later
      roomNumber = rooms[0];
      // return the first available room in the list
      return rooms[0];
    }
    else
    {
      for( std::size_t i = 14; i < 20; i++ )
        { rooms.push_back( roomsAvailable[i] ); }

      std::cout << "\nAvailable Rooms Include: ";

      for( std::size_t i = 0; i < rooms.size(); i++ )
        { std::cout << "\nRoom " << rooms[i] << " "; }

      // save for later
      roomNumber = rooms[0];
      // return the first available room in the list
      return rooms[0];
    }
  }

  int ReservationBase::createReservation( int room_Num, std::string Guest_Name, int credit_Card )
  {
    char user_decision;
    std::cout << "Using the information in Checkout, would you like to finalize and create a Reservation? (Y/N):"
              << " ";
    std::cin >> user_decision;

    if(user_decision == 'Y')
    {
      if(room_Num == 15 && Guest_Name == "Cesar Gutierrez" && credit_Card == 123456789)
      {
        reservationNumber = 222;
        return reservationNumber;
      }
      return -1;
    }
    else
    {
      return 0;
    }
  }

  int ReservationBase::searchForReservation(std::string full_Name)
  {
    char user_decision;
    std::cout << "Did you provide us with your Full Name? (Y/N):" << " ";
    std::cin >> user_decision;
    if(user_decision == 'Y' && full_Name == "Cesar Gutierrez")
    {
      return 222;
    }
    else
    {
      return 0;
    }
  }

  int ReservationBase::deleteReservation(int reservationNum)
  {
    char user_decision;
    std::cout << "Is " + std::to_string( reservationNum ) + " your Reservation Number? (Y/N) :";
    std::cin >> user_decision;
    if( user_decision == 'Y' )
    {
      reservationNum = 0;
      return reservationNum;
    }
    else
    {
      std::cout << "Failed to delete reservation." << " ";
      return reservationNum;
    }
  }


  ReservationBase::~ReservationBase() = default;

  }    // namespace Domain::Reservation
