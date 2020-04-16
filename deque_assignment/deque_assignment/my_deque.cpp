// define my_deque here
#include "my_deque.h"
#include <vector>
#include <string>
#include <exception>

using namespace std; 

my_deque::my_deque(unsigned int initial_size) 
	:sizeOfArray(initial_size)
{
	rindex = sizeOfArray / 2; 
	lindex = rindex - 1; 
	arrayDeque = new int[sizeOfArray];
}

my_deque::my_deque(const my_deque& d)
	
{
	sizeOfArray = d.sizeOfArray; 
	rindex = d.sizeOfArray / 2; 
	lindex = rindex - 1; 
	arrayDeque = new int[d.sizeOfArray];
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
	unsigned int counter = 0; 
	for (unsigned int i = 0; i < sizeof(arrayDeque); i++) {
		if (arrayDeque[i] != NULL) {
			counter++; 
		}
	}
	return counter; 
}

unsigned int my_deque::get_size() {
	unsigned int sizeArray =  sizeof(arrayDeque);
	return sizeArray;
}

unsigned int my_deque::get_lIndex() {
	unsigned int arraySize = sizeof(arrayDeque);
	 int leftIndex = (arraySize/2) -1; 
	if (arrayDeque[leftIndex] != NULL) {
		for (int i = leftIndex; i >= 0; i--) {
			if (arrayDeque[i] == NULL) {
				leftIndex = i; 
				break; 
			}
			else {
				leftIndex = -1;
			}
		}
	}
	return leftIndex; 


}

unsigned int my_deque::get_rIndex() {
	unsigned int arraySize = sizeof(arrayDeque);
	unsigned int rightIndex = arraySize / 2;

	if (arrayDeque[rightIndex] != NULL) {
		for (unsigned int i = rightIndex; i < sizeof(arrayDeque); i++) {
			if (arrayDeque[i] == NULL) {
				rightIndex = i;
				break;
			}
			else {
				rightIndex = sizeof(arrayDeque);
			}
		}
	}

	return rightIndex; 
}

void my_deque::push_back(int v) {
	unsigned int numElements = get_used(); 
	unsigned int rightIndex = get_rIndex(); 
	unsigned int leftIndex = get_lIndex(); 
	unsigned int arraySize = get_size(); 

	//number of elements in deque is greater than size/2 and no space left to insert next element
	if (numElements > (arraySize / 2) && rightIndex == arraySize) {
	//array has to be doubled in size
		unsigned int newSize = arraySize + arraySize; 
		 int* newArray = new int [newSize];

		for (unsigned int i = 0; i < arraySize; i++) {
			newArray[i] = arrayDeque[i];
		}
		
		sizeOfArray = sizeof(newArray);
		memcpy(arrayDeque, newArray, sizeOfArray);
		lindex = get_lIndex(); 
		rindex = get_rIndex(); 
		arrayDeque[rindex] = v;
		rindex++; 
		
	}
	//elements in deque need to be recentered, that is all no new array is needed
	else if (numElements <= (arraySize / 2) && rightIndex == arraySize) {
		 int* newArray = new int[arraySize];
		unsigned int reCenterIndex = arraySize / 4; 
		 
		for (unsigned int i = lindex; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++;
		}
		sizeOfArray = sizeof(newArray);
		memcpy(arrayDeque, newArray, sizeOfArray);
		lindex = get_lIndex(); 
		rindex = get_rIndex(); 
		arrayDeque[rindex] = v; 
		rindex++; 
		
	}
	else if (numElements < (arraySize / 8)) {
		
		unsigned int newSize = arraySize / 2; 
		 int* newArray = new int[newSize];
		unsigned int reCenterIndex = newSize / 4; 

		for (unsigned int i = lindex; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++; 
		}
		sizeOfArray = newSize;
		//memcpy(arrayDeque, newArray, sizeOfArray);
		arrayDeque = newArray; 
		lindex = get_lIndex();
		rindex = get_rIndex();
		arrayDeque[rindex] = v;
		rindex++; 
	}
	else {
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
	if (numElements > (arraySize / 2) && leftIndex == -1) {
		//array has to be doubled in size
		unsigned int newSize = arraySize + arraySize;
		int* newArray = new int[newSize];

		for (unsigned int i = 0; i < arraySize; i++) {
			newArray[i] = arrayDeque[i];
		}

		sizeOfArray = sizeof(newArray);
		memcpy(arrayDeque, newArray, sizeOfArray);
		lindex = get_lIndex();
		rindex = get_rIndex();
		arrayDeque[lindex] = v;
		lindex--;

	}
	//elements in deque need to be recentered, that is all no new array is needed
	else if (numElements <= (arraySize / 2) && leftIndex == -1) {
		 int* newArray = new int[arraySize];
		unsigned int reCenterIndex = arraySize / 4;

		for (unsigned int i = lindex; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++;
		}
		sizeOfArray = sizeof(newArray);
		memcpy(arrayDeque, newArray, sizeOfArray);
		lindex = get_lIndex();
		rindex = get_rIndex();
		arrayDeque[lindex] = v;
	    lindex--;

	}
	else if (numElements < (arraySize / 8)) {

		unsigned int newSize = arraySize / 2;
		 int* newArray = new int[newSize];
		unsigned int reCenterIndex = newSize / 4;

		for (unsigned int i = lindex; i < rindex; i++) {
			newArray[reCenterIndex] = arrayDeque[i];
			reCenterIndex++;
		}
		sizeOfArray = sizeof(newArray);
		memcpy(arrayDeque, newArray, sizeOfArray);
		lindex = get_lIndex();
		rindex = get_rIndex();
		arrayDeque[lindex] = v;
		lindex--;
	}
	else {
		arrayDeque[lindex] = v;
		lindex--;
	}

}

int my_deque::pop_back() {
	unsigned int numElements = get_used(); 
	unsigned int element = 0; 
	if (numElements > 0) {
		element = arrayDeque[rindex - 1];
		arrayDeque[rindex - 1] = NULL; 
		rindex--; 
		numElements = get_used(); 
		unsigned int arraySize = sizeof(arrayDeque);
		if (numElements < (arraySize)/8) {
			if ((arraySize / 2) >= my_deque::sizeOfArray) {
				unsigned int newSize = (arraySize / 2);
				 int* newArray = new int[newSize];
				unsigned int reCenterIndex = newSize / 4;

				for (unsigned int i = lindex; i < rindex; i++) {
					newArray[reCenterIndex] = arrayDeque[i];
					reCenterIndex++;
				}
				sizeOfArray = sizeof(newArray);
				memcpy(arrayDeque, newArray, sizeOfArray);
				lindex = get_lIndex();
				rindex = get_rIndex();
			}
			
			

		}
		return element; 
	
	}
	else {
		//throw an exception
		throw "There are no elements to pop off the deque.";
	}
}


int my_deque::pop_front() {
	unsigned int numElements = get_used();
	unsigned int element = 0;
	if (numElements > 0) {
		element = arrayDeque[lindex + 1];
		arrayDeque[lindex + 1] = NULL;
		lindex++;
		numElements = get_used();
		unsigned int arraySize = sizeof(arrayDeque);
		if (numElements < (arraySize / 8)) {
			if ((arraySize / 2) >= my_deque::sizeOfArray) {
				unsigned int newSize = ((arraySize) / 2);
				 int* newArray = new int[newSize];
				unsigned int reCenterIndex = newSize / 4;

				for (unsigned int i = lindex; i < rindex; i++) {
					newArray[reCenterIndex] = arrayDeque[i];
					reCenterIndex++;
				}
				sizeOfArray = sizeof(newArray);
				memcpy(arrayDeque, newArray, sizeOfArray);
				lindex = get_lIndex();
				rindex = get_rIndex();
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
	if (i >= 0 && i < sizeof(arrayDeque)) {
		int& alpha = arrayDeque[i];
		return alpha;
	}
	else {
		throw std::exception();
	}
	
	
}