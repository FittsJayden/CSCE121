# include "Passport.h"
# include "StatePark.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list
Passport::Passport(std::string camperName, bool isJuniorPassport) : camperName{camperName}, isJuniorPassport(isJuniorPassport), parksVisited{} {}

string Passport::getCamperName() {
	return this-> camperName;
}

bool Passport::checkJuniorPassport() {
	return this-> isJuniorPassport;
}

void Passport::addParkVisited(StatePark* park) {
	INFO(park)


	// TODO: implement function
	parksVisited.push_back(park);
	park->addCamper(this);//?????????????(found in lecture week 11)
}

double Passport::getMilesHiked() {
	// TODO: (optional) implement function

	return 0.0;
}

int Passport::getHikerLevel() {
	// TODO: (optional) implement function

	return 0;
}
