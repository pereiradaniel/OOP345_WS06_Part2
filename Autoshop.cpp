#include "Autoshop.h"
#include "Car.h"

namespace sdds {

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);	// push theVehicle into m_vehicles vector!
		return *this;
	}

	void Autoshop::display(std::ostream& out) {
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		
		std::vector<Vehicle*>::iterator v;
		for (v = m_vehicles.begin(); v != m_vehicles.end(); v++) {
			(*v)->display(out);
			out << std::endl;
		}

		out << "--------------------------------\n";
	}

	// Iterate through Autoshop vector m_vehicles and delete each one
	Autoshop::~Autoshop() {
		std::vector<Vehicle*>::iterator v;
		for (v = m_vehicles.begin(); v != m_vehicles.end(); v++) {
			delete* v;
		}
	}
} // sdds