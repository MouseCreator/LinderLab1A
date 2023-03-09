#include "SignedNumber.h"
#include "FiniteNumber.h"


void testPositiveNumbers() {
	PositiveNumber a = PositiveNumber("1234");
	PositiveNumber b = PositiveNumber("9925");
	PositiveNumber c = a + b;
	PositiveNumber d = b - a;
	PositiveNumber e = b * a;
	std::cout << c.toString() << std::endl;
	std::cout << d.toString() << std::endl;
	std::cout << e.toString() << std::endl;
}

void testSignedNumbers() {
	FiniteNumber finite = FiniteNumber("x10 1344");

	SignedNumber signedN = SignedNumber("200");
	SignedNumber signedM = SignedNumber("-300");
	signedN.addTo(signedM);
	std::cout << signedN.toString() << std::endl;
	signedN.substract(signedM);
	std::cout << signedN.toString() << std::endl;
	signedN.multiplyBy(signedM);
	std::cout << signedN.toString() << std::endl;
	
}

void testDifferentSize() {
	PositiveNumber a = PositiveNumber("10000");
	PositiveNumber b = PositiveNumber("1");
	PositiveNumber c = a - b;
	PositiveNumber d = b - a;
	std::cout << c.toString() << std::endl;
	std::cout << d.toString() << std::endl;
}



int main() {
	testDifferentSize();
}