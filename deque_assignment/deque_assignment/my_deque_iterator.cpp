// define my_deque_iterator here
/*
#include "my_deque_iterator.h"
#include "my_deque.h"
using namespace std;

my_deque_iterator::my_deque_iterator(int* alpha, my_deque* beta)
	
{
	if (alpha == NULL) {
		curr = nullptr; 
		
		deque = beta;
	}
	
	else if (alpha > beta->get_rIndex) {
		curr = alpha;
		
		deque = beta;
	}
	else {
		curr = alpha;
		deque = beta;
	}

}

my_deque_iterator my_deque_iterator::operator+ (int n) {
	if (n >= 0) {
		my_deque_iterator newIterator = my_deque_iterator(curr + n, deque);
		return newIterator;
	}
	else {
		//return an invalid iterator here
		my_deque_iterator newIterator = my_deque_iterator(nullptr, deque);
		return newIterator;
	}
	
}

my_deque_iterator& my_deque_iterator::operator+= (int n) {
	if (n >= 0) {
		my_deque_iterator& newIterator = my_deque_iterator(curr + n, deque);
		return newIterator; 
	}
	else {
		my_deque_iterator& newIterator = my_deque_iterator(nullptr, deque);
		return newIterator;
	}
}

int& my_deque_iterator::operator* () {
	if (curr == nullptr) {
		throw std::exception();
	}
	else {
		int& result = *curr; 
		return result;
	}
}

bool my_deque_iterator::operator<(const my_deque_iterator compare_against) const {
	if (curr == nullptr || deque->get_size < compare_against.deque->get_size) {
		throw std::exception();
	}
	else {
		int* firstResult = curr; 
		int currIndex = 0; 
		
		for (int i = deque->get_lIndex; i < deque->get_rIndex; i++) {
			if (deque->get_mem == firstResult) {
				currIndex = i; 
			}
		}

		int* secondResult = compare_against.curr; 
		int secondCurrIndex = 0; 
		
			for (int i = compare_against.deque->get_lIndex; i < compare_against.deque->get_rIndex; i++) {
				if (compare_against.deque->get_mem == secondResult) {
					secondCurrIndex = i; 
				}
		}
			if (currIndex < secondCurrIndex) {
				return true; 
			}
			else {
				return false; 
			}
	}
}

bool my_deque_iterator::operator== (const my_deque_iterator coco) const {
	if (deque->get_mem == coco.deque->get_mem) {
		if (curr == coco.curr) {
			return true; 
		}
		else {
			return false; 
		}
	}
	else {
		
		return false; 
	}
}

int* my_deque_iterator::get_mem() {
	int memory = *curr; 
	return &memory; 
}
*/