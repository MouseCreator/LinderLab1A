#pragma once
#include <iostream>
#include <vector>
/**
* Class for number in infinite field
*
*
*/
class Number {
private:
	std::vector<int> digits; //digits as decimal numbers
protected:
	void parseDigits(std::string str) {
		digits.clear();

		std::size_t size = str.size();
		for (int i = size - 1; i >= 0; i--) {
			digits.push_back(str[i] - '0');
		}
	}

public:
	Number() {
		digits.push_back(0);
	}
	Number(std::string digitsString) {
		parseDigits(digitsString);
	}
	Number addTo(Number other) {
	}
	std::string toString() {
		std::string result = "";
		for (int i : digits) {
			result += (i + '0');
		}
		return result;
	}
};