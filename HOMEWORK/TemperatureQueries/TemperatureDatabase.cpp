# include "TemperatureDatabase.h"
# include <fstream>


using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	std::ifstream inFile;
	inFile.open(filename);

	if (!inFile.is_open()) {
		cout << "File cannot be opened" << endl;
		return;
	}

	LinkedList* newList = new LinkedList();

	string area;
	int year;
	int month;
	double temperature;

	while (!inFile.eof()) {
		inFile >> area >> year >> month >> temperature;
		newList->insert(area, year, month, temperature);
	}
	inFile.close();

}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
}
