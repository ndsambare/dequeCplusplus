// define my_deque here
#include "my_deque.h"
#include <vector>
#include <string>
#include <exception>

using namespace std; 

my_deque::my_deque(unsigned int initial_size) 
	:sizeOfArray(initial_size)
{
	init_size = initial_size; 
	rindex = sizeOfArray / 2; 
	lindex = rindex - 1; 
	arrayDeque = new int[sizeOfArray];
}

my_deque::my_deque(const my_deque& d)
	
{
	arrayDeque = new int[d.sizeOfArray];
	init_size = d.sizeOfArray; 
	sizeOfArray = d.sizeOfArray; 
	rindex = d.rindex;
	lindex = d.lindex; 
	for (int i = 0; i < sizeOfArray; i++) {
		arrayDeque[i] = d.arrayDeque[i];
	}
	
}

my_deque::~my_deque() {
	
	delete arrayDeque; 
	arrayDeque = NULL; 
}

unsigned int my_deque::get_used() {
	//unsigned int counter = 0; 
	//for (unsigned int i = 0; i < sizeOfArray; i++) {
	//	if (arrayDeque[i] == 0) {
	//		
	//	}
	//	else {
	//		counter++;
	//	}
	//}
	//return counter; 
	return (rindex - lindex - 1); 
}

unsigned int my_deque::get_size() {
	
	return sizeOfArray;
}

unsigned int my_deque::get_lIndex() {
	
	 /*lindex = (sizeOfArray/2) -1; 
	 if (arrayDeque[lindex] == NULL) {
		 return lindex;
	 }
	 else {
		 for (int i = lindex; i >= 0; i--) {
			 if (arrayDeque[i] == NULL) {
				 lindex = i;
				 return lindex;
			 }

		 }
	 }
	 lindex = 0; 
		if (lindex == 0 && arrayDeque[lindex] != NULL) {
			lindex = 4294967295;
			return lindex;
		}*/
	
	return lindex; 
}

unsigned int my_deque::get_rIndex() {
	
	return rindex; 
}

void my_deque::push_back(int v) {
	unsigned int numElements = get_used(); 
	unsigned int rightIndex = get_rIndex(); 
	unsigned int leftIndex = get_lIndex(); 
	unsigned int arraySize = get_size(); 

	//number of elements in deque is greater than size/2 and no space left to insert next element on right
	if ((numElements +1) > (arraySize / 2) && rightIndex == arraySize) {
	//array has to be doubled in size
		unsigned int newSize = arraySize + arraySize; 
		 int* newArray = new int [newSize];
		 unsigned int reCenterIndex = (newSize / 4) + 1;
		 //store where the value for the new lindex after the array is recentered
		 leftIndex = reCenterIndex - 1;

		 //fill all of the new array with all elements from arrayDeque
		for (unsigned int i = lindex +1; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++;
		}
		
		rightIndex = reCenterIndex; 
		sizeOfArray = newSize;

		//make arrayDeque point to the new array that is double the size filled with all the elements
		arrayDeque = newArray;
		lindex = leftIndex;
		rindex = rightIndex;
		arrayDeque[rindex] = v;
		rindex++; 
		
	}
	//elements in deque need to be recentered but we do not have to increase the size of the array
	else if ((numElements+1) <= (arraySize / 2) && rightIndex == arraySize) {
		 int* newArray = new int[arraySize];
		unsigned int reCenterIndex = (arraySize / 4) + 1; 
		//store where the value for the new lindex after the array is recentered
		leftIndex = reCenterIndex - 1; 

		//fill up the new array with all elements that were in the old array
		for (unsigned int i = lindex + 1; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++;
		}
		//store the value for the new rindex after the array is recentered
		rightIndex = reCenterIndex; 
		arrayDeque = newArray;
		lindex = leftIndex; 
		rindex = rightIndex; 
		arrayDeque[rindex] = v; 
		rindex++; 
		
	}
	//we need to cut the array in half
	//else if (numElements < (arraySize / 8)) {
	//	
	//	unsigned int newSize = arraySize / 2; 
	//	 int* newArray = new int[newSize];
	//	unsigned int reCenterIndex = (newSize / 4) + 1; 
	//	//get the value for the updated left idex after recentering
	//	leftIndex = reCenterIndex - 1; 

	//	//fill up the new array with all elements that were in the old array
	//	for (unsigned int i = lindex; i < rindex; i++) {
	//		newArray[reCenterIndex] = arrayDeque[i];
	//		reCenterIndex++; 
	//	}


	//	//get the value for the updated right Index after recentering
	//	rightIndex = reCenterIndex; 
	//	sizeOfArray = newSize;
	//	arrayDeque = newArray;
	//	lindex = leftIndex;
	//	rindex = rightIndex; 
	//	arrayDeque[rindex] = v;
	//	rindex++; 
	//}
	else {
		rindex = rightIndex; 
		lindex = leftIndex;
		arrayDeque[rindex] = v; 
		rindex++;

	}

}

void my_deque::push_front(int v) {
	unsigned int numElements = get_used();
	unsigned int rightIndex = get_rIndex();
	unsigned int leftIndex = get_lIndex();
	unsigned int arraySize = get_size();

	//number of elements in deque is greater than size/2 and no space left to insert next element
	//since unsigned if i do (0 minus 1) I get this big number, but I would rather it be -1
	if ((numElements +1) > (arraySize / 2) && leftIndex == 0) {
		//array has to be doubled in size

		unsigned int newSize = arraySize + arraySize;
		int* newArray = new int[newSize];

		unsigned int reCenterIndex = newSize / 4; 
		leftIndex = reCenterIndex - 1; 
		for (unsigned int i = lindex + 1; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++;
		}
	
		rightIndex = reCenterIndex; 
		sizeOfArray = newSize;
		arrayDeque = newArray;
		
		lindex = leftIndex; 
		rindex = rightIndex; 
		arrayDeque[lindex] = v;
		lindex--;

	}
	//elements in deque need to be recentered, that is all no new array is needed
	else if ((numElements +1) <= (arraySize / 2) && leftIndex == 0) {
		 int* newArray = new int[arraySize];
		unsigned int reCenterIndex = arraySize / 4;
		leftIndex = reCenterIndex - 1;
		for (unsigned int i = lindex +1; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++;
		}
		
		rightIndex = reCenterIndex; 
		
		arrayDeque = newArray;
		lindex = leftIndex;
		rindex = rightIndex;
		arrayDeque[lindex] = v;
	    lindex--;

	}
	//else if ((numElements+1) < (arraySize / 8)) {

	//	unsigned int newSize = arraySize / 2;
	//	 int* newArray = new int[newSize];
	//	unsigned int reCenterIndex = newSize / 4;
	//	leftIndex = reCenterIndex - 1; 
	//	for (unsigned int i = lindex; i < rindex; i++) {
	//		newArray[reCenterIndex] = arrayDeque[i];
	//		reCenterIndex++;
	//	}
	//	
	//	rightIndex = reCenterIndex; 
	//	sizeOfArray = newSize;
	//	arrayDeque = newArray;
	//	lindex = leftIndex;
	//	rindex = rightIndex;
	//	arrayDeque[lindex] = v;
	//	lindex--;
	//}
	else {
		lindex = leftIndex; 
		rindex = rightIndex; 
		arrayDeque[lindex] = v;
		lindex--;
	}

}

int my_deque::pop_back() {
	unsigned int numElements = get_used(); 
	unsigned int element = 0; 
	if (numElements > 0) {
		element = arrayDeque[rindex - 1];
		rindex--;
		
		numElements = get_used(); 
		
		if (numElements < (sizeOfArray/8)) {
			
			if ((sizeOfArray / 2) >= init_size) {
				unsigned int newSize = (sizeOfArray / 2);
				 int* newArray = new int[newSize];
				unsigned int reCenterIndex = newSize / 4;
				unsigned int leftIndex = reCenterIndex - 1; 

				for (unsigned int i = lindex +1; i < rindex; i++) {
					newArray[reCenterIndex] = arrayDeque[i];
					reCenterIndex++;
				}
				unsigned int rightIndex = reCenterIndex; 
				sizeOfArray = newSize;
				arrayDeque = newArray;
				lindex = leftIndex; 
				rindex = rightIndex; 
			}
			
			

		}
		
		return element; 
	
	}
	else {
		//throw an exception
		throw std::exception();
	}
}


int my_deque::pop_front() {
	unsigned int numElements = get_used();
	unsigned int element = 0;

	if (numElements > 0) {
		element = arrayDeque[lindex + 1];
		lindex++;
		
		numElements = get_used();
		
		if (numElements < (sizeOfArray / 8)) {
			if ((sizeOfArray / 2) >= init_size) {
				unsigned int newSize = (sizeOfArray / 2);
				 int* newArray = new int[newSize];
				unsigned int reCenterIndex = (newSize / 4) +1;
				unsigned int leftIndex = reCenterIndex - 1; 

				for (unsigned int i = lindex +1; i < rindex; i++) {
					newArray[reCenterIndex] = arrayDeque[i];
					reCenterIndex++;
				}

				unsigned int rightIndex = reCenterIndex; 
				sizeOfArray = newSize;
				arrayDeque = newArray;
				lindex = leftIndex;
				rindex = rightIndex;
			}



		}
		
		return element;

	}
	else {
		//throw an exception
		throw std::exception();
		
	}	
}

int* my_deque::get_mem() {
	 int* address = arrayDeque; 
	 return address; 
}

int& my_deque::operator[](const unsigned int& i) {
	unsigned int element = get_used();
	if (i < element) { 
		
			return arrayDeque[lindex + 1 + i];
		 
		
	}
	else {
		throw std::exception();
	}
	
	
}