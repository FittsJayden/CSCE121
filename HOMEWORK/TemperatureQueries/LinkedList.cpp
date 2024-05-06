# include <iostream>
# include <string>
# include <sstream>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream, std::cout, std::endl;

LinkedList::LinkedList() : tail(), head(), _size(0) {
	// TODO: implement this function
	tail = nullptr;
	head = nullptr;
}

LinkedList::~LinkedList() {
	// TODO: implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : _size(source._size) {
	this->head = new Node(source.head->data.id, source.head->data.year, source.head->data.month, source.head->data.temperature);

	Node* curr = this->head;
	Node* oneAfter = source.head->next;

	while(oneAfter != nullptr) {
		curr->next = new Node(oneAfter->data.id, oneAfter->data.year, oneAfter->data.month, oneAfter->data.temperature);
		curr = oneAfter;
		oneAfter = oneAfter->next;
	}

	this->tail = curr;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
	clear();

	this->head = new Node(source.head->data.id, source.head->data.year, source.head->data.month, source.head->data.temperature);

	Node* curr = this->head;
	Node* oneAfter = source.head->next;

	while(oneAfter != nullptr) {
		curr->next = new Node(oneAfter->data.id, oneAfter->data.year, oneAfter->data.month, oneAfter->data.temperature);
		curr = oneAfter;
		oneAfter = oneAfter->next;
	}

	this->tail = curr;
	this->_size = source._size;

	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
	Node* curr = new Node(location, year, month, temperature);
	Node* count = this->head;

	if (this->_size == 0) {
		this->head = curr;
		this->tail = curr;
		_size += 1;
		return;
	}

	else if (_size == 1) {
		if (*curr < *count) {
			curr->next = count;
			this->head = curr;
			this->tail = curr->next;
		}

		else {
			this->head->next = curr;
			this->tail = curr;
		}

		_size += 1;
		return;
	}


	if (*curr < *count) {
		curr->next = count;
		this->head = curr;
		_size += 1;
		return;
	}

	count = this->head->next;
	Node* prev = nullptr;

	for (int i = 1; i < _size; i++) {

		if (*curr < *count) {

			if (prev = nullptr) {
				this->head->next = curr;
			}

			else {
				prev->next = curr;
			}

			curr->next = count;
			this->_size += 1;

			// if (i == _size - 1) {
			// 	this->tail = curr;
			// }

			return;
		}
		
		if (prev = nullptr) {
			prev = this->head;
		}

		prev = prev->next;
		count = count->next;

	}

}

void LinkedList::clear() {
	// TODO: implement this function
	Node* curr = this->head;

	while (curr != nullptr) {
		delete curr;
		curr = curr->next;
	}

	tail = nullptr;
	head = nullptr;
	_size = 0;
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return this->head;
}

string LinkedList::print() const {
	string outputString;


	// TODO: implement this function
	Node* curr = this->head;

	for (int i = 0; i < _size; i++) {
		outputString = outputString + curr->data.id + " " + std::to_string(curr->data.year)+ " " + std::to_string(curr->data.month) + " " + std::to_string(curr->data.temperature) + "\n";
		cout << std::to_string(curr->data.year) << endl;
		curr = curr->next;
	}

	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
