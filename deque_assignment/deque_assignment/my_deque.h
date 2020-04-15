#pragma once
// declare your my_deque class here
#include <string>
#include <array>
#include <cstddef>
using namespace std; 

class my_deque {
	unsigned int rindex;
	unsigned int lindex;
	unsigned int sizeOfArray;
	unsigned int* arrayDeque;

public: 
	my_deque(unsigned int initial_size);
	my_deque(const my_deque& d);
	~my_deque();
	unsigned int get_used(); 
	unsigned int get_size(); 
	unsigned int get_lindex(); 
	unsigned int get_rindex(); 
	void push_back(int v);
	void push_front(int v);
	int pop_back(); 
	int pop_front(); 
	int* get_mem(); 
	int& operator[](const unsigned int& i);
	

	
};