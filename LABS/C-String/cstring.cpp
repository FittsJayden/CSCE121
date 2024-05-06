#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
	unsigned int i = 0;
  // returns the length of the string including zero (0)
	for (i = 0; str[i] != '\0'; i++) {	
	}
	return i;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
	unsigned int i = 0;
	
  	for (i = 0; str[i] != character && str[i] != '\0'; i++) {	
	}
  	return i;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
	if (str1[i] == str2[i]) {
	}
	else {
		return false;
	}
  }

  return true;
}