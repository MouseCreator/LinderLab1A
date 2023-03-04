#pragma once
#include <iostream>
#include <vector>
#include <cmath>
/**
* Class for number in infinite field
*
*
*/
class PositiveNumber {
private:
	std::vector<int> digits; //digits as decimal numbers
	const int vectorP = 10;
protected:
	void parseDigits(std::string str) {
		digits.clear();
		std::size_t size = str.size();
		reverse(str.begin(), str.end());
		for(char ch : str) {
			digits.push_back(ch - '0');
		}
	}

public:
	PositiveNumber() {
	}
	PositiveNumber(std::string digitsString) {
		parseDigits(digitsString);
	}
	int& operator[](int i) {
		return digits[i];
	}
	int& operator[](std::size_t i) {
		return digits[i];
	}


	PositiveNumber operator+(const PositiveNumber& n) const {
		return addTo(n);
	}
	PositiveNumber operator-(const PositiveNumber& n) const {
		return substractFrom(n);
	}
	bool operator==(PositiveNumber& n) const {
		return equals(n);
	}
	bool operator!=(PositiveNumber& n) const {
		return !equals(n);
	}
	bool equals(PositiveNumber& n) const {
		if (digits.size() != n.digits.size())
			return false;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] != n[i])
				return false;
		}
		return true;
	}
	bool operator>(PositiveNumber& n) const {
		if (digits.size() > n.digits.size())
			return true;
		if (digits.size() < n.digits.size())
			return false;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == n[i])
				continue;
			return digits[i] > n[i];
		}
		return false;
	}
	bool operator>=(PositiveNumber& n) const {
		if (digits.size() > n.digits.size())
			return true;
		if (digits.size() < n.digits.size())
			return false;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == n[i])
				continue;
			return digits[i] > n[i];
		}
		return true;
	}
	bool operator<(PositiveNumber& n) const {
		if (digits.size() < n.digits.size())
			return true;
		if (digits.size() > n.digits.size())
			return false;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == n[i])
				continue;
			return digits[i] < n[i];
		}
		return false;
	}
	bool operator<=(PositiveNumber& n) const {
		if (digits.size() < n.digits.size())
			return true;
		if (digits.size() > n.digits.size())
			return false;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == n[i])
				continue;
			return digits[i] < n[i];
		}
		return true;
	}
	/**
	* Adds to positive numbers
	*/
	PositiveNumber addTo(PositiveNumber other) const{
		std::size_t minSize = std::min(digits.size(), other.digits.size());
		bool addOne = false;
		PositiveNumber sum = PositiveNumber();
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
	/**
	* 
	* Subsracts two numbers. Returns the module of the result.
	*/
	PositiveNumber substractFrom(PositiveNumber other) const {
		return substractFrom(*this, other);
	}
	PositiveNumber substractFrom(PositiveNumber n1, PositiveNumber n2) const {
		std::vector<int>* bigger = (n1 > n2) ? &n1.digits : &n2.digits;
		std::vector<int>* smaller = (n1 <= n2) ? &n1.digits : &n2.digits;
		bool substractOne = false;

		std::size_t minSize = smaller->size();
		PositiveNumber dif = PositiveNumber();
		int i = 0;
		for (; i < minSize; i++) {
			int v = bigger->at(i) - smaller->at(i) - substractOne;
			substractOne = v < 0;
			dif.digits.push_back(v + vectorP * substractOne);
		}
		while (i < digits.size()) {
			int v = bigger->at(i) - smaller->at(i) - substractOne;
			substractOne = v < 0;
			dif.digits.push_back(v + vectorP * substractOne);
			i++;
		}

		return dif;
	}

	std::string toString() {
		std::string result = "";
		if (digits.empty())
			return "0";
		for (int i : digits) {
			result += (i + '0');
		}
		reverse(result.begin(), result.end());
		return result;
	}
};