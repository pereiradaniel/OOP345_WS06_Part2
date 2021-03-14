#include <cctype>
#include <iostream>
#include <iomanip>

#include "Car.h"

namespace sdds {
	Car::Car(std::istream& fin) {
		// Create stings for processing usage
		std::string tag;
		std::string speed;
		std::string condition;

		bool digital = true;
		
		// Read data from file
		getline(fin, tag, ',');
		getline(fin, make, ',');
		getline(fin, condition, ',');
		getline(fin, speed, ',');
		
		// Process 'make'
		make.erase(0, make.find_first_not_of(' '));
		make.erase(make.find_last_not_of(' ') + 1);

		// Process 'condition'
		condition.erase(0, condition.find_first_not_of(' '));
		condition.erase(condition.find_last_not_of(' ') + 1);
		
		// Process 'speed'
		speed.erase(0, speed.find_first_not_of(' '));
		speed.erase(speed.find_last_not_of(' ') + 1);
		
		// Detect if new car
		if (condition.empty() || condition[0] == ' ') {
			cond = 'n';
		}
		else if (condition[0] == 'n' || condition[0] == 'u' || condition[0] ==
			'b') {
			cond = condition[0];
		}
		// Detect invalid car
		else {
			std::string err = "Invalid record!";
			throw err;
		}
		// Check speed
		for (int tmp : speed) {
			if (tmp < 48 || tmp > 57) {
				digital = false;
				break;
			}
		}
		if (digital) {
			tSpeed = std::stod(speed);
		}
		// Detect invalid!
		else {
			std::string err = "Invalid record!";
			throw err;
		}
	}

	std::string Car::condition() const {
		std::string condition;
		// Set condition of car:
		switch (cond) {
		case 'n':
			condition.assign("new");
			break;
		case 'u':
			condition.assign("used");
			break;
		case 'b':
			condition.assign("broken");
			break;
		}
		return condition; // Return the condition
	}

	double Car::topSpeed() const {
		return tSpeed;	// Simply return the tSpeed
	}

	void Car::display(std::ostream& out) const {
		out << "| " << std::right << std::setw(10) << make;
		out << " | " << std::left << std::setw(6) << condition();
		out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed();
		out << " |";
	}
} // sdds