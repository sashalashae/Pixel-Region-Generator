#include <string>
#include <cxxtest/TestSuite.h>

#include "array_stack.h"

#include <cstdlib>
#include <stack>
#include <iostream>
using namespace std;

template class ArrayStack<int>;

class ArrayStackTests : public CxxTest::TestSuite
{
public:
	//tests to see if the arraystack is empty
	void testEmpty1(void)
	{
		ArrayStack<int> s1;
		s1.push(1);
		s1.push(2);
		TS_ASSERT(s1.isempty() == false);

	}

	//tests the top method
	void testTop1(void)
	{
		ArrayStack <int> s2;
		s2.push(1);
		s2.push(2);
		s2.push(3);
		s2.pop();
		TS_ASSERT(s2.top() == 2);
	}

	//tests the push method
	void testpush(void)
	{
		ArrayStack <int> s3;
		s3.push(1);
		TS_ASSERT(s3.top() == 1);
	}
	//tests the copy constructor
	void testca(void)
	{
		ArrayStack<int> s1;
		s1.push(1);
		s1.push(2);
		ArrayStack<int> s2;
		s2 = s1;	
		TS_ASSERT(s2.top() == 2);
	}
	void testexcep(void)
	{
		ArrayStack<int> s2;
		s2.push(1);
		s2.pop();
		TS_ASSERT(s2.isempty() == true);
	}

	void testCC(void)
	{
		ArrayStack<int> s3;
		s3.push(1);
		s3.push(2);
		ArrayStack<int> s4 = s3;
		s4.pop();
		TS_ASSERT(s4.top() == 1);
		s4.pop();
		///TS_ASSERT_THROWS(s4.top(), range_error);
	}
	void testoverflow(void)
	{
		ArrayStack<int> s5;
		for (int i = 0; i < 150; i++)
		{
			s5.push(i);
		}
		TS_ASSERT(s5.top() == 149);
	}
	
	

};
