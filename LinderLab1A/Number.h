#pragma once
#include <iostream>
#include <vector>
#include <cmath>
/**
* Class for number in infinite field
*
*
*/
class Number {
private:
	std::vector<int> digits; //digits as decimal numbers
	const int vectorP = 10;
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
	}
	Number(std::string digitsString) {
		parseDigits(digitsString);
	}
	int& operator[](int i) {
		return digits[i];
	}

	Number addTo(Number other) {
		int minSize = std::min(digits.size(), other.digits.size());
		bool addOne = false;
		Number sum = Number();
		int i = 0;
		for (; i < minSize; i++) {
			int v = digits[i] + other[i] + addOne;
			addOne = v > vectorP;
			sum.digits.push_back(v - vectorP * addOne);
			
		}
		while (i < digits.size()) {
			int v = digits[i] + addOne;
			addOne = v > vectorP;
			sum.digits.push_back(v - vectorP * addOne);
			
			i++;
		}
		while (i < other.digits.size()) {
			int v = other[i] + addOne;
			addOne = v > vectorP;
			sum.digits.push_back(v % vectorP * addOne);
			
			i++;
		}
		if (addOne) {
			sum.digits.push_back(1);
		}
		return sum;
	}
	std::string toString() {
		std::string result = "";
		if (digits.empty())
			return "0";
		for (int i = digits.size() - 1; i >= 0; i--) {
			result += (digits[i] + '0');
		}
		return result;
	}
};