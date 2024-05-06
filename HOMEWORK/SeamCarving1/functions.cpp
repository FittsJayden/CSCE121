#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
	ifstream inFS;
	string preamble;
	int colorRange;
	int bufferR;
	int bufferG;
	int bufferB;



	inFS.open(filename);

	if (!inFS.is_open()) {
		throw runtime_error("Failed to open " + filename);
	}

	inFS >> preamble;
	inFS >> width;
	inFS >> height;
	inFS >> colorRange;

	if (preamble != "P3" && preamble != "p3") {
		throw runtime_error("Invalid type " + preamble);
	}
	if (width > MAX_WIDTH || height > MAX_HEIGHT || width < 1 || height < 1) {
		throw runtime_error("Invalid dimensions");
	}



	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			inFS >> bufferR;
			inFS >> bufferG;
			inFS >> bufferB;

			if (bufferR > 255 || bufferR < 0 || bufferG > 255 || bufferG < 0 || bufferB > 255 || bufferB < 0 || inFS.fail()) {
				throw runtime_error("Invalid color value");
			}

			image[j][i].r = bufferR;
			image[j][i].g = bufferG;
			image[j][i].b = bufferB;
		}
	}

	inFS >> bufferB;
	if (!inFS.fail()) {
		throw runtime_error("Too many values");
	}

	inFS.close();

}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
	ofstream outFS;

	outFS.open(filename);
	if (!outFS.is_open()) {
		throw runtime_error("Failed to open " + filename);
	}

	outFS << "P3\n" << width << " " << height << endl << "255" << endl;


	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			outFS << image[j][i].r << endl;
			outFS << image[j][i].g << endl;
			outFS << image[j][i].b << endl;
		}
	}

	outFS.close();
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	// TODO: implement (part 1)
	unsigned int energy;
	unsigned int deltaX;
	unsigned int deltaY;

	unsigned int xPlus = x + 1;
	unsigned int xMinus = x - 1;
	unsigned int yPlus = y + 1;
	unsigned int yMinus = y - 1;

	if (x == 0) {
		xMinus = width - 1;
	}

	if (y == 0) {
		yMinus = height - 1;
	}

	if (y == (height - 1)) {
		yPlus = 0;
	}

	if (x == (width - 1)) {
		xPlus = 0;
	}




	deltaX = pow(image[xMinus][y].r - image[xPlus][y].r, 2) + pow(image[xMinus][y].g - image[xPlus][y].g, 2) + pow(image[xMinus][y].b - image[xPlus][y].b, 2);
	deltaY = pow(image[x][yMinus].r - image[x][yPlus].r, 2) + pow(image[x][yMinus].g - image[x][yPlus].g, 2) + pow(image[x][yMinus].b - image[x][yPlus].b, 2);
	energy = deltaX + deltaY;

	return energy;
}

// uncomment functions as you implement them (part 2)

// unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
//   // TODO: implement (part 2)
// }

// void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
// }
