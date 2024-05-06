#include <iostream>

void rotateRight(char**& ary, unsigned int& numRows, unsigned int& numCols) {
    if (ary == nullptr || numRows == 0 || numCols == 0) {
        throw runtime_error("Bad input");
    }

    char** newAry = new char*(numCols);

    for (unsigned int i = 0; i < numCols; i++) {
        newAry[i] = new char[numRows];
    }

    newNumCols = numRows;
    newNumRows = numCols;

    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {
            newAry[j][newNumCols - (i + 1)] = ary[i][j];
        }
    }


    for (unsigned int i = 0; i < numRows; i++) {
        delete [] ary[i];
    }
    delete [] ary;

    ary = newAry;
    numRows = newNumRows;
    numCols = newNumCols;

}
