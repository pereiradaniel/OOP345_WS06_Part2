#include "Car.h"
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;	// the percentage (stored as a number between 0 an 1) by which this `Racecar` can boost its top speed.
	public:
		Racecar(std::istream& in); // calls the constructor from `Car` to build the subobject, and then it extracts the last field from the stream containing the booster bonus.
		void display(std::ostream& out) const; // calls `Car::display()` to print the information about the car, and adds `*` at the end.
		double topSpeed() const; // returns the top speed of the car, including any booster effects.
	};
} // sdds