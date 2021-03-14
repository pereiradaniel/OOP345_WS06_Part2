#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster{ 0 };

	public:
		explicit Racecar(std::istream& in);
		void display(std::ostream& out) const override;
		// Use nodiscard to issue warning from compiler
		// reference: https://en.cppreference.com/w/cpp/language/attributes/nodiscard
		[[nodiscard]] double topSpeed() const override;
	};
} // sdds
#endif