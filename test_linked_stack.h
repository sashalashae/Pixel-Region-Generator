#include <string>
#include <cxxtest/TestSuite.h>

#include "linked_stack.h"
//#include "linked_stack.txx"

#include <cstdlib>
#include <stack>

template class LinkedStack<int>;

class LinkedStackTests : public CxxTest::TestSuite
{
public:
   void testPush(void)
   {
	   LinkedStack<int> s1;
	   s1.push(1);
	   TS_ASSERT(s1.top() == 1);
   }
   void testPop(void)
   {
	   LinkedStack<int> s2;
	   s2.push(1);
	   s2.push(3);
	   s2.push(2);
	   s2.pop();
	   TS_ASSERT(s2.top() == 3);
   }
   void testempty(void)
   {
	   LinkedStack<int> s3;
	   
	   TS_ASSERT(s3.isempty() == true);
   }
   void testempty2(void)
   {
	   LinkedStack<int> s1;
	   s1.push(1);
	   TS_ASSERT(s1.isempty() == false);
   }
   void testca(void)
   {
	   LinkedStack<int> s1;
	   s1.push(1);
	   s1.push(2);
	   LinkedStack<int> s2;
	   s2 = s1;
	   TS_ASSERT(s2.top() == 2);
   }
   void testee(void)
   {
	   LinkedStack<int> ss;
	   ss.push(1);
	   ss.pop();
	   TS_ASSERT_EQUALS(ss.isempty(),true);
   }
   void testthrowe(void)
   {
	   
   }
};
