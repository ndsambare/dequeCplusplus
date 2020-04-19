Answer any exam questions here
Name: Namit Sambare
WUSTL ID: 465010


IMPORTANT NOTE: I have declared all methods and implemented all methods in my_deque_iterator.cpp, but I was not able to implement 
the begin and end functionality. I am really hoping that I can still get some credit for the code I have completed still as it is 
a lot of it (I worked on the iterator implementation for at least 8 hours). However, I wanted to let you know I do in fact have code in the iterator.cpp as I will be commenting it all out
so that my deque tests still pass. 



Deep vs. Shallow Copy: 
 	Below is my code experiment to determine if the std::deque() constructor makes a shallow or deep copy.

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

	Well, first of all, the experiment quite literally prints out to the console whetheer the constructor for the std::deque() makes a deep copy 
	or a shallow copy. From the experiement, I learned that the std::deque() makes a deep copy. The experiement first makes a deque named "alpha"
	that is filled with 5 numbers (each of them are the number 69). I then print out the memory address of alpha by doing 'cout << &alpha << endl;'
	The & is a referencing operator that gives the memory location of alpha, and I print this out. Next, I create another deque object named "beta" to which I pass in 
	"alpha," a copy of the first deque object I have already made. I then use the referencing operator (which gives the memory location of the object I am referencing)
	to print out the memory location of beta. Once I run this code snippet, I examine the two values that were printed out: the first is the memory location address
	of the first deque object (alpha) and the second printed value is the memory location of the second deque object (beta), which I set equal to a copy of the first object. 
	Since, I created th beta deque object by setting it equal to a copy of alpha, if the constructor made a shallow copy, both the memory locations of alpha and beta would be the same. 
	However, if the memory locations of alpha and beta are different, this insinuates that the constructor made a deep copy. This is true because a shallow copy simply 
	re-aliases existing resources, and if a shallow copy was made beta would've pointed to the already existing memory location of alpha. 
	A deep copy makes a new and separate copy with a new memory location, and this is precisely what happens. 

	Extra Credit: 
	Test I created: getSmaller and getSmallerTwo
	Explanation of getSmaller:
	So, in my review of the test cases, I noticed that there is one resizing test case that the test suite does not include. And this is the test case 
	of cutting the size of the array in half when the number of elements in it is less than an eigth of the array's size. To test this, 
	I make a deque object and initialize to have an initial size of 4. I then fill the deque with 32 elements until the size of the deque increases to 64. 
	I then take out the 32 elements using the pop_front() method. According to the correct resizing logic, as elements are removed from the deque, 
	the deque size should be cut in half when the number of elements in the array is less than an eigth of the size. So, before I start popping, 
	there are 32 elements in a deque size of 64. So, the first halved resize is supposed to happen when there are less than 8 elements. When there are 
	less than 8 elements, the deque should go from a size of 64 to 32. Then again, as I keep popping elements, when the number of elements is 
	less than an eigth of the size (32 at this point) the size is cut in half. So when there re less than 4 elements, the size is cut in half from 
	32 to 16. Again, when there are less 16/8 = 2 elements, the size of the array will be cut in half from 16 to 8. And finally, when there are less than 1 (8/8 = 1) element, 
	the size of the array will be cut in half from 8 to 4. The final size of the deque after all the pushing and popping should then be 4 if the resizing functionality of the 
	pop methods works. During the iterative pops from the deque, whenever the array is supposed to be cut in half, my code makes sure that the size it will be decreased to is not 
	less than initial size. I even check this in another test called getSmallerTwo. In getSmallerTwo, I have the same code as getSmaller but the initial size of the array is set to 8, 
	so the final size of the deque won't be 4 because that is less than 8. Thus, the final size should be 8 and it is.
