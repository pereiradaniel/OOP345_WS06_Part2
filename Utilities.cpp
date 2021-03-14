#include "Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* ptr = nullptr;	// Set to nullptr!
		
		// Create temporary string and read line into it
		std::string temp;
		getline(in, temp);
		
		// Process temp string
		temp.erase(0, temp.find_first_not_of(' '));
		std::stringstream line(temp);

		if (!temp.empty()) {
			if (toupper(temp[0]) == 'C') {
				ptr = new Car(line);
			}
			else if (toupper(temp[0]) == 'R') {
				ptr = new Racecar(line);
			}
			// Detect uncrecognized record and throw
			else {
				std::string tag{};
				getline(line, tag, ',');
				throw "Unrecognized record type: [" + tag + "]";
			}
		}
		else {
			ptr = nullptr;
		}
		return ptr;
	}
} // sdds