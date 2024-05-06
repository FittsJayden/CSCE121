# include "Database.h"
# include "StatePark.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list
Database::Database() : stateParkList{}, camperList{} {}

Database::~Database() {
	for (unsigned int i = 0; i < stateParkList.size(); ++i) {
		delete stateParkList.at(i);
	}
	
	for (unsigned int i = 0; i < camperList.size(); ++i) {
		delete camperList.at(i);
	}
}

void Database::addStatePark(string parkName, double entranceFee, double trailMiles) {
	INFO(parkName)
	INFO(entranceFee)
	INFO(trailMiles)

	stateParkList.push_back(new StatePark(parkName, entranceFee, trailMiles));//no need to define a pointer StatePark when the function can be passed as a pointer?
	
}

void Database::addPassport(string camperName, bool isJuniorPassport) {
	INFO(camperName)
	INFO(isJuniorPassport)

	// TODO: implement function
	this-> camperList.push_back(new Passport(camperName, isJuniorPassport));
}

void Database::addParkToPassport(string camperName, string parkName) {
	INFO(camperName)
	INFO(parkName)
	Passport* passBuffer = nullptr;
	StatePark* parkBuffer = nullptr;

	// TODO: implement function
	for (long unsigned int i = 0; i < stateParkList.size(); i++) {
		if (stateParkList[i]->getParkName() == parkName) {
			parkBuffer = stateParkList[i];
			break;
		}
	}
	for(long unsigned int i = 0; i < camperList.size(); i++) {
		if (camperList[i]->getCamperName() == camperName) {
			passBuffer = camperList[i];
			break;
		}
	}

	passBuffer->addParkVisited(parkBuffer);
}

vector<string> Database::getParksInRevenueRange(double lowerBound, double upperBound) {
	INFO(lowerBound)
	INFO(upperBound)

	// TODO: (optional) implement function
	
	return {};
}

vector<string> Database::getHikersAtLeastLevel(int level) {
	INFO(level)

	// TODO: (optional) implement function

	return {};
}
