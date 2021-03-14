#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		std::string make{};
		char cond{};
		double tSpeed{};

	public:
		Car() = default;
		explicit Car(std::istream& fin); // fin = file in
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		~Car() override = default;
	};
} // sdds
#endif
