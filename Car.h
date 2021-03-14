#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>

#include "Vehicle.h" // inherit from Vehicle
namespace sdds {
	class Car : public Vehicle {
		std::string maker;		// name of make
		std::string condition;	// condition: new, used, or broken.
		double tSpeed;			// top speed (do not confuse with function topSpeed()!
	
	public:
		Car(std::istream&);						// a custom constructor that receives an object of type `std::istream&` as parameter.
		std::string condition() const;			// a query that returns `new`, `used` or `broken`, representing the condition of the car
		double topSpeed() const;				// a query that returns `new`, `used` or `broken`, representing the condition of the car
		void display(std::ostream& out) const; // a query that inserts in the first parameter the content of the car object
	}; // Car
} // sdds
#endif