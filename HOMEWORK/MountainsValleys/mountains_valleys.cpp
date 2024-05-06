#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	int botBound;
	int topBound;
	bool boundCheck = false;

	// TODO(student): print prompt for input
	while (boundCheck == false) {
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> botBound >> topBound;
		boundCheck = is_valid_range(botBound, topBound);
		if (boundCheck == false) {
			cout << "Invalid Input" << endl;
		}
	}

	// TODO(student): compute and display solution
	count_valid_mv_numbers(botBound, topBound);

	return 0;
}