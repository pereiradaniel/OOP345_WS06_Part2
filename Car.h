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
		// Use nodiscard to issue warning from compiler
		// reference: https://en.cppreference.com/w/cpp/language/attributes/nodiscard
		[[nodiscard]] std::string condition() const override;
		[[nodiscard]] double topSpeed() const override;
		void display(std::ostream& out) const override;
		~Car() override = default;
	};
} // sdds
#endif