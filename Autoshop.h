#include <vector>
#include "Vehicle.h"
#include <list>
using namespace std;
namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;	// a vector that store all the vehicles available at this autoshop.
	public:
		Autoshop& operator+=(Vehicle* theVehicle);	// adds the vehicle received as parameter into the `m_vehicles` vector.
		void display(ostream&) const;				// iterates over the vehicles stored in `m_vehicles` and prints them into the parameter
		~Autoshop();	// This function should iterate over the objects stored in the vector, and delete each one of them

		// a **template** function that iterates over the vehicles stored in the `m_vehicles`, and adds to the second parameter all vehicles for which the `test` is true.
		template <typename T>
		void select(T test, list<const Vehicle*>& vehicles)
		{
			for (auto& m_vehicle : m_vehicles)
			{
				if (test(m_vehicle))
				{
					vehicles.push_back(m_vehicle);
				}
			}
		}
	};
} // namespace sdds