#include "Number.h"

int main() {
	PositiveNumber a = PositiveNumber("1234");
	PositiveNumber b = PositiveNumber("9925");
	PositiveNumber c = a + b;
	PositiveNumber d = b - a;
	
	std::cout << d.toString() << std::endl;
}