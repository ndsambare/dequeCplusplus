// deque_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include "my_deque.h"
using namespace std; 

int main()
{

	//std::deque<int> alpha (5,69);
	//std::cout << &alpha << endl;

	//std::deque<int> beta(alpha);
	//std::cout << &beta << endl; 

	//if (&alpha == &beta) {
	//	std::cout << "This is a shallow copy.";
	//}
	//else {
	//	std::cout << "This is a deep copy.";
	//}

	int init_size = 32; 
	int n = 32;

	my_deque d = my_deque(init_size);

	for (int i = 0; i < n; i += 2) {
		d.push_front(i);
		d.push_back(i + 1);
	}

	my_deque d_copy(d);
	

	

	
	    d.get_mem();
		d.get_size();


	// Jon Shidal: Feel free to use this file to test your program via the command line with tests you create.
    std::cout << "Hello World!\n";
}
