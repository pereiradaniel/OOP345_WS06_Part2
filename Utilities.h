#ifndef SDDS_UTILITY_H
#define SDDS_UTILITY_H
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
namespace sdds
{
	Vehicle* createInstance(std::istream& in); // This function should extract data from the parameter;
}
#endif