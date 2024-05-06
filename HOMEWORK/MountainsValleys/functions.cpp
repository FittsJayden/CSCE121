#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (a < 10) {
		return false;
	}
	else if (b >= 10000) {
		return false;
	}
	else if (a > b) {
		return false;
	}
	else {
		return true;
	}
	
}

char classify_mv_range_type(int number) {
	char morv = 'z';
	int digit1;
	int digit2;

	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	while (true) {
		digit1 = number % 10;
		number /= 10;
		if (number == 0) {
			return morv;
		}
		digit2 = number % 10;



		if (digit1 > digit2) {
			if (morv == 'z' || morv == 'V') {
				morv = 'M'; //mountain
			}
			else {
				break;
			}
		}
		else if (digit1 < digit2) {
			if (morv == 'z' || morv == 'M') {
				morv = 'V'; //mountain
			}
			else {
				break;
			}
		}
		else {
			break;
		}
		
	}
	return 'N';

}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	char countBuffer;
	int mountains = 0;
	int valleys = 0;

	for (int i = a; i <= b; i++) {
		countBuffer = classify_mv_range_type(i);
		if (countBuffer == 'M') {
			mountains += 1;
		}
		else if (countBuffer == 'V') {
			valleys += 1;
		}
	}
	cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << endl;

}