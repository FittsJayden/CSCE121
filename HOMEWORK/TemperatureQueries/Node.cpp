# include <string>
# include <iostream>
# include "Node.h"

using std::string;

Node::Node() : next(nullptr), data(TemperatureData{}) {}

Node::Node(string id, int year, int month, double temperature) : next(nullptr), data(TemperatureData{id, year, month, temperature}) {
	// TODO: implement this function
}

Node::Node(const Node& src) : next(nullptr), data(TemperatureData{src.data.id, src.data.year, src.data.month, src.data.temperature}) {}

bool Node::operator<(const Node& b) {
	// TODO: implement this function
	return (this->data < b.data);
}
