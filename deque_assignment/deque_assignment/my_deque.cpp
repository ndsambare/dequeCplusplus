// define my_deque here
#include "my_deque.h"
#include <vector>
#include <string>

using namespace std; 

my_deque::my_deque(unsigned int initial_size) 
	:sizeOfArray(initial_size)
{
	rindex = sizeOfArray / 2; 
	lindex = rindex - 1; 
	arrayDeque = new unsigned int[sizeOfArray];
}

my_deque::my_deque(const my_deque& d)
	
{
	rindex = d.sizeOfArray / 2; 
	lindex = rindex - 1; 
	arrayDeque = new unsigned int[d.sizeOfArray];
}

my_deque::~my_deque() {
	delete &rindex;
	rindex = NULL; 
	delete &lindex; 
	lindex = NULL;
	delete arrayDeque; 
	arrayDeque = NULL; 
}

unsigned int my_deque::get_used() {
	for (unsigned int i = 0; i < sizeof(arrayDeque); i++) {

	}
}