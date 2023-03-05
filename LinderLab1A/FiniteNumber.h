#pragma once
#include "PositiveNumber.h"

class FiniteNumber : public PositiveNumber {
private: 
	PositiveNumber p = PositiveNumber("10");
	void setP(PositiveNumber p) {
		this->p = p;
		toFieldSize();
	}
	void toFieldSize() {
		//TODO
	}

public:
	FiniteNumber(std::string from, PositiveNumber p) {
		this->digits = parseDigits(from);
		setP(p);
	}
	/**
	* Input: string of value "xP N", where P - is field size, N - positive integer
	*
	*/
	FiniteNumber(std::string from) {
		if (from[0] == 'x') {
			from = from.substr(1);
		}
		std::string p = from.substr(0, from.find_first_of(' '));
		std::string n = from.substr(from.find_first_of(' '));
		this->digits = parseDigits(n);
		setP(p);
	}

};

