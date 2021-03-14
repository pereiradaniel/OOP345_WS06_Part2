#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles; // Vector containing the vehicles of the autoshop.

	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out);
		~Autoshop();

		// Templated function:
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			std::vector<Vehicle*>::iterator i;
			for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
} // sdds
#endif