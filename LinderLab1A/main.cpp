#include "Number.h"

int main() {
	PositiveNumber a = PositiveNumber("1234");
	PositiveNumber b = PositiveNumber("9925");
	PositiveNumber c = a + b;
	PositiveNumber d = b - a;
	PositiveNumber e = b * a;
	std::cout << c.toString() << std::endl;
	std::cout << d.toString() << std::endl;
	std::cout << e.toString() << std::endl;
}