# include "TemperatureData.h"
# include <iostream>
# include <string>
using std::string, std::stoi, std::cout, std::endl;

TemperatureData::TemperatureData() : id(0), year(0), month(0), temperature(0) {
	// TODO: implement this function
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) : id(id), year(year), month(month), temperature(temperature) {
	// TODO: implement this function
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	// TODO: implement this function
	bool lessThan = false;

	if (stoi(this->id) < stoi(b.id)) {
		lessThan = true;
	}


	else if (stoi(this->id) == stoi(b.id)) {
		if (this->year < b.year) {
			lessThan = true;
		}
		

		else if (this->year == b.year) {
			if (this->month < b.month) {
				lessThan = true;
			}


		}
	}
	

	return lessThan;
}

