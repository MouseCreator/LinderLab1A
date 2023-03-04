#include "Number.h"

int main() {
	Number a = Number("1234");
	Number b = Number("9925");
	Number c = a.addTo(b);
	
	std::cout << c.toString() << std::endl;
}