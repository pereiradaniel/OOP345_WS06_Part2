#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

namespace sdds {
	Vehicle* createInstance(std::istream& in);
} // sdds
#endif