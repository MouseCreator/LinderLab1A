#include "SignedNumber.h"
#include "FiniteNumber.h"
int main() {
	PositiveNumber a = PositiveNumber("1234");
	PositiveNumber b = PositiveNumber("9925");
	PositiveNumber c = a + b;
	PositiveNumber d = b - a;
	PositiveNumber e = b * a;
	std::cout << c.toString() << std::endl;
	std::cout << d.toString() << std::endl;
	std::cout << e.toString() << std::endl;


	FiniteNumber finite = FiniteNumber("x10 1344");

	SignedNumber signedN = SignedNumber("200");
	SignedNumber signedM = SignedNumber("-300");
	signedN.addTo(signedM);
	std::cout << signedN.toString() << std::endl;
}