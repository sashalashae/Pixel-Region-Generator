//Sasha Morgan
//ECE 2574 - P2 10/10/16
//ECE 2574 MWF 12:20-1:10, Torg 1000
//Purpose:  To practice with implementing array stacks


//What we know about Stacks:
//Last in First Out, Push insert an item into the stack, Pop the item back out of the stack
//Circular buffer, you can get the item in reverse order, meaning you can get the last item first
//size is dynamically allocated

//What we need:
//Default constructor, copy constructor, copy assignment, destructor, pop, push, top, isempty methods.
#include "array_stack.h"

//Default Constructor
template<typename T>
ArrayStack<T>::ArrayStack() :stackTop(0), maxStackSize(100)
{
	alist = new T[maxStackSize]; //creates a new array of size 100
}

//Destructor
template <typename T>
ArrayStack<T>::~ArrayStack()
{
	delete[] alist;
}

//Copy Constuctor
template<typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> &other)
{
	alist = nullptr; //set list to null
	copy(other); //calls the function
}

//Copy Assignment
template<typename T>
ArrayStack<T> &ArrayStack<T> :: operator=(const ArrayStack<T> other)
{
	if (this != &other)
	{
		copy(other);
	}
	return*this;
}

//Sets the value of stacktop which determines if the stack is empty
template<typename T>
void ArrayStack<T>::stackinital()
{
	stackTop = 0;
}

//This method checks to see if the stack is empty
template<typename T>
bool ArrayStack<T>::isempty()
{
	bool check = false; //default variable
	if (stackTop == 0) //Indicates a stack is empty
	{
		check = true;
	}
	return check;
}

//This method adds a item to the stack array
template<typename T>
void ArrayStack<T>::push(const T& item)
{
	if (alist == nullptr)
	{
		alist = new T[maxStackSize];
	}

	if (stackTop != maxStackSize) //makes sure the stack is not full
	{
		alist[stackTop] = item; //adds the item to the array
		stackTop++;//updates the position
	}
	
	if (stackTop == maxStackSize)
	{
		T* curr = alist;
		alist = new T[maxStackSize * 2];
		for (int i = 0; i < maxStackSize; i++)
		{
			alist[i] = curr[i];
		}
		delete[] curr;
		maxStackSize = maxStackSize * 2;

		/*
	maxStackSize = maxStackSize * 2;
	T*wanna = alist; //creates a pointer array
	alist = new T(maxStackSize); //If it is full we need to double the size
	int i = 0; //counter variable
	while (i < maxStackSize/2) //runs throught the size of the arraystack
	{
	alist[i] = wanna[i]; //transfers the information from one arraystack to the other arraystack
	i++; //updates the loop
	}
	alist = wanna; //sets the stacks equal to the content of each other
	delete[] wanna; //frees memory from the array
	maxStackSize = maxStackSize * 2;
	*/
	
	}
	alist[stackTop] = item; //adds the item to the array
	//stackTop++;
	
}

//Returns the top element
template<typename T>
const T& ArrayStack<T>::top()
{
	if (stackTop != 0)//checks to see if the stack is empty
	{
		return alist[stackTop - 1]; //returns the top element in the stack
	}
	else
	{
		throw std::range_error("Sorry, this might sound embarassing, but your stack is empty.");
	}
}

//Deletes an element from the stack
template<typename T>
void ArrayStack<T>::pop()
{
	if (stackTop != 0) //checks for an empty stack
	{
		stackTop--; //decrements the position value
	}

}


//creates a copy of the stack and uses the stack that is being copied as a parameter
template<typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& other)
{
	//delete[] alist; //free memory
	maxStackSize = other.maxStackSize; //sets the variables
	stackTop = other.stackTop;//creates a new list
	alist = new T[maxStackSize]; //copies the list
	for (int j = 0; j < stackTop; j++) //adds the items to the list
	{
		alist[j] = other.alist[j];
	}
}
