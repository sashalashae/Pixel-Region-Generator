#include "linked_stack.h"
#include <cassert>

//default constructor
template <typename T>
LinkedStack<T>::LinkedStack()
{
	stackTop = nullptr;
}

//Copy Constructor 
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> &og)
{
	stackTop = nullptr;
	copy(og);
	
}

//Copy assignment
template <typename T>
LinkedStack<T> &LinkedStack<T> :: operator=(LinkedStack<T> og)
{
	//want to avoid a self copy
	if (this != &og)
	{
		stackTop = nullptr;
		copy(og);
	}
	return*this;
}

//destructor
template<typename T>
LinkedStack<T>::~LinkedStack()
{
	initializeStack();
}

//Pushes an element to the top of the stack
template<typename T>
void LinkedStack<T>::push(const T& item)
{
	//creates and sets the new node
	nodeType<T> *nNode = new nodeType<T>;

	//points to the new node to the data and sets it equal to the item, stores the item
	nNode->data = item;

	//insert the newnode before the stacktop
	nNode->llink = stackTop;

	//sets stacktop to point to the top node
	stackTop = nNode;
	
}

template<typename T>
void LinkedStack<T>::pop()
{
	nodeType<T> *current;
	if (stackTop != nullptr)
	{
		current = stackTop; //sets the new node equal to the current
		stackTop = stackTop->llink;//advance it to the next node
		delete current; //delete the top node
	}
	

}


//Returns the top value of the stack, as long as the stack is not empty
template <typename T>
const T& LinkedStack<T>::top()
{
	if (stackTop != nullptr)//makes sure the stack top is not null
	{
		return stackTop->data;
	}
	else
	{
		throw std::range_error("Sorry, this might sound embarassing, but your stack is empty.");
	}
}

//Checks to see if the stack is empty
template<typename T>
bool LinkedStack<T>::isempty()
{

	bool status = false;

	//checks to see if the stack is a null pointer
	if (stackTop == nullptr) 
	{
		//changes the default value to true
		status = true; 
	}
	return status; 
}

template <typename T>
void LinkedStack<T>::copy(const LinkedStack<T> & og)
{
	nodeType<T> *nNode, *current, *fin;
	if (stackTop != nullptr)
	{
		initializeStack();
	}
	if (og.stackTop == nullptr)
	{
		stackTop = nullptr;
	}
	else
	{
		current = og.stackTop;
		stackTop = new nodeType<T>;//copy the element
		stackTop->data = current->data;//copy the info
		stackTop->llink = nullptr;//set it to null
		fin = stackTop;//point to node
		current = current->llink;
		while (current != nullptr)//copies the remailing stack
		{
			nNode = new nodeType<T>;
			nNode->data = current->data;
			nNode->llink = nullptr;
			fin->llink = nNode;
			fin = nNode;
			current = current->llink;
		}
	}
}

template <typename T>
void LinkedStack<T>::initializeStack()
{
	nodeType<T> *curr;
	while (stackTop != nullptr)
	{
		curr = stackTop;
		stackTop = stackTop->llink;
		delete curr;
	}
}