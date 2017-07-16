// This is the header file for the linked stack
#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include "abstract_stack.h"



template <typename T>
class LinkedStack : public AbstractStack<T>
{
public:
	// constructor
	LinkedStack();

	//destructor
	~LinkedStack();

	// copy constructor
	LinkedStack(const LinkedStack<T> &og);

	// copy assignment
	LinkedStack &operator=(LinkedStack<T> og);

	// push an item of type T into the stack
	// my throw std::bad_alloc on failure
	void push(const T& item);

	// pop (remove) the top item from the stack
	void pop();

	// return item at the top of the stack
	const T& top();

	// returns true if the stack is empty
	bool isempty();

private:

	template <typename X>
	struct nodeType
	{
		X data; //store the information from the stack
		nodeType<X>* llink; //link to the next node
		
		
	};
	nodeType<T> *stackTop;
	void copy(const LinkedStack<T>&);
	void initializeStack();

};
#include "linked_stack.txx"
#endif // _LINKED_STACK_H_


