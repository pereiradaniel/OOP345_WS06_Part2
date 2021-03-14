#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string t_boost; // Temporary string
		getline(in, t_boost, '\n'); // Read line into temp string
		m_booster = std::stod(t_boost); // Set m_booster using temp booster
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);  // Return calculated boost
	}
} // sdds