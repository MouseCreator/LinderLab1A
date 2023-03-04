#pragma once
#include <iostream>
#include <vector>
/**
* Number class represents a number in some field
*
*
*/
class Number {
private:
	
	std::vector<int> digits;

	void parseDigits(std::string str) {

	}

public:
	Number() {
		digits.push_back(0);
	}
	Number(std::string digitsString) {

	}
	Number addTo(Number other) {

	}
	std::string toString() {
		std::string result = "";
		for (int i : digits) {
			result += i;
		}
		return result;
	}
};