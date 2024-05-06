#include <iostream>

unsigned int rightShift(unsigned int num, unsigned int digits_to_shift) {
    int numBuffer;
    int size;
    int sizeFinder = num;
    int firstInt = 10;

    while (sizeFinder != 0) {// finds size of num
        size += 1;
        sizeFinder /= 10;
    }
    
    if (digits_to_shift > size) { // throws error if num doesn't have enough digits to be shifted
        throw invalid_argument("Not enough digits to shift");
    }

    if (size == 1) { //a signle digit num can't be shifted
        return num;
    }

    for (size = size - 2; size != 0; size--) { //determines the tens place of the leftmost digit in num
        firstInt *= 10;// this allows us to multiply by this number every time we move a single digit from the right to the left just by adding
    }

    for (int i = digits_to_shift; i > 0; i--) {
        numBuffer = num % 10;// finds ones place digit

        num /= 10;//takes off ones place digit

        num += numBuffer * firstInt;//numBuffer (ones place digit) is multiplied by the 10^n where n is number of digits in num - 1. It's then added to num.
    }

    return num;

}