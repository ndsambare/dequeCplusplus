#pragma once
// declare my_deque_iterator here
#include <string>
#include <array>
#include <cstddef>
#include "my_deque.h"
using namespace std;

class my_deque_iterator {


public:
	my_deque_iterator (int*, my_deque*);
	my_deque_iterator operator+ (int n);
	my_deque_iterator& operator+= (int n);
	int& operator* (); 
	bool operator<(const my_deque_iterator compate_against) const;
	bool operator== (const my_deque_iterator) const;
	int* get_mem();




private:
	int* curr; 
	my_deque* deque; 

};



