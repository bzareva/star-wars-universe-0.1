#include<iostream>
#include "Jedi.h"

int main() {

	Jedi j1(43, 34.3, Rank::INITIATE, "PESHO", "light");
	std::cout << j1;

//	std::cout << "hello";

	system("pause");
	return 0;
}