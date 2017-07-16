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


#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include "abstract_stack.h"

template <typename T>
class ArrayStack : public AbstractStack<T>
{
public:
	// constructor
	ArrayStack();

	//destructor
	~ArrayStack();

	// copy constructor
	ArrayStack(const ArrayStack<T> &other);

	// copy assignment
	ArrayStack &operator=(ArrayStack<T> other);

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

	//T* sa;//pointer to the stack array
	//int size;//stack size
	//int tp; //shows the top of the stack
	int maxStackSize;
	int stackTop;
	T* alist;
	void stackinital();
	void copy(const ArrayStack<T>&);

};
#include "array_stack.txx"
#endif // _ARRAY_STACK_H_
