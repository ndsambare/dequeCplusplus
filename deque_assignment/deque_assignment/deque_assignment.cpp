// deque_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
using namespace std; 

int main()
{

	std::deque<int> alpha (5,69);
	std::cout << &alpha << endl;

	std::deque<int> beta(alpha);
	std::cout << &beta << endl; 

	if (&alpha == &beta) {
		std::cout << "This is a shallow copy.";
	}
	else {
		std::cout << "This is a deep copy.";
	}




	// Jon Shidal: Feel free to use this file to test your program via the command line with tests you create.
    std::cout << "Hello World!\n";
}
