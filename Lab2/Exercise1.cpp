// implementation file
#include "blackHawk.hpp"
#include <iostream>

int main(){
  // create the user object
  blackHawk client{};

  // begin the session
  client.setActive( true );

  // set car purchase to 0 since this is the beginning of the program
  client.setPurchase( 0 );

  while( client.getActive() == true ){
    // client chooses from 4 options in the main menu
    client.option = client.mainMenu();

    if( client.option == 1 ){
      // client decided to buy a car
      client.setPurchase( 1 );
      blackHawk car{0000, "color:N/A", "name:N/A"};
      client.addToGarage( car );
    }
    else if( client.option == 2 ){
      // client wants to compare purchased cars
      client.showCars();
    }
    else if( client.option == 3 ){
      // client would like to drive a purchased car and use the features

      // select a car
      client.showCars();
      blackHawk car = client.selectCar(0);

      // turn the car on
      car.setPower( 1 );

      // while the car is on
      while( car.getPower() == true )
      {
        // ask client which feature they would like to use,
        // and then use it
        car.setFeature( car.getFeature() );
      }
    }
    else if( client.option == 4 ){
      // client has asked to generate a report
      client.queryClient();
    }
    else if( client.option == 5 ){
      // client would like to end the session
      client.setPower(-1);
    }
    else{
      // default error message
      client.setPurchase(-1);
    }
  }

  return 0;
}
