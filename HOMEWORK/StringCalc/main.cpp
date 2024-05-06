#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "./string_calculator.h"

using namespace std;

int main() {
    string input1;
    string input2;
    string operation;
    string answer;

    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    
    // TODO(student): implement the UI
    do {
    cout << ">> ";
    cin >> input1;
    if (input1 == "q" || input1 == "quit") {
        cout << "\nfarvel!" << endl;
        return 0;
    }
    cin >> operation;
    cin >> input2;
    cout << endl;


    try {
        if (operation[0] == '+') { //call addition
            answer = add(input1, input2);
        }
        else if (operation[0] == '*') { //call multiplication
            answer = multiply(input1, input2);
        }
        else {
            throw (invalid_argument("Operator is missing or invalid"));
        }
    }

    catch (const exception& err) {
        cout << endl << err.what() << endl;
        return 0;
    }

    cout << "ans =\n\n" << "    " << answer << "\n\n";
    }
    while (true);

}

