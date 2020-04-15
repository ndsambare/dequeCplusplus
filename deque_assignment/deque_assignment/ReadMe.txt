Answer any exam questions here
Name: Namit Sambare
WUSTL ID: 465010

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