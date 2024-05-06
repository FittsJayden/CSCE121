#include <iostream>
#include <string>
#include "./string_calculator.h"

using namespace std;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    if (digit > 47 && digit < 58) {
    }
    else {
        throw invalid_argument("One of the inputs has a non-integer!");
    }

    unsigned int decimal = digit - 48;
    return decimal;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    char digit = decimal + 48;
    if (digit > 47 && digit < 58) {
    }
    else {
        throw invalid_argument("One of the inputs has a non-integer!");
    }

    return digit;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement

    for (int i = 0; num[0] == '0'; i++) {
            num.erase(0,1);
            if (num.size() == 1) {
                break;
            }
    }


    return num;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    if (lhs == "0" || rhs == "0") {
        if (lhs == "0") {
            if (rhs == "0") {
                return "0";
            }
            return rhs;
        }
        else {
            return lhs;
        }
    }
    string answer;
    int buffer;
    int carry = 0;

    int leftSize = lhs.size();
    int rightSize = rhs.size(); // this technically limits the size of integers we can use

    if (leftSize > rightSize) {
        for (int i = 0; rightSize + i != leftSize; i++) {
            rhs.insert(0, "0");
        }
        rightSize = leftSize;
    }
    else if (rightSize > leftSize) {
        for (int i = 0; leftSize + i != rightSize; i++) {
            lhs.insert(0, "0");
        }
        leftSize = rightSize;
    }
    answer.insert(0, rightSize + 1, '0');

    for (int j = rightSize - 1; j >= 0; j--) {
        buffer = digit_to_decimal(lhs[j]) + digit_to_decimal(rhs[j]);
        buffer += carry;
        carry = buffer / 10;
        buffer %= 10;
        answer[j + 1] = decimal_to_digit(buffer);
    }

    if (carry > 0) {
        answer[0] = '1';
    }

    answer = trim_leading_zeros(answer);

    return answer;


}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    if (lhs == "0" || rhs == "0") {
        return "0";
    }

    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    string answer = "0";
    string partialBuffer = "";
    int buffer;
    int carry;

    int rightSize = rhs.size();
    int leftSize = lhs.size();


    if (rightSize > leftSize) {
        buffer = leftSize;
        leftSize = rightSize;
        rightSize = buffer;

        partialBuffer = lhs;
        lhs = rhs;
        rhs = partialBuffer;
    }
    partialBuffer = "";






    for (int i = rightSize - 1; i >= 0; i--) {
        partialBuffer.insert(0, rightSize - (i + 1), '0');
        carry = 0;
        for (int j = leftSize - 1; j >= 0; j--) {
            buffer = digit_to_decimal(lhs[j]) * digit_to_decimal(rhs[i]);
            buffer += carry;
            carry = buffer / 10;
            buffer %= 10;
            partialBuffer.insert(0, 1, decimal_to_digit(buffer));
        }
        if (carry != 0) {
            partialBuffer.insert(0, 1, decimal_to_digit(carry));
        }
        answer = add(answer, partialBuffer);
        partialBuffer = "";
    }
    
    return answer;
}
