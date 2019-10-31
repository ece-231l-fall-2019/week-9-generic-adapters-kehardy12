#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
#include "Stack.h"
#include "Queue.h"

typedef List<std::string> StringList;
typedef List<int> IntList;
//typedef List<double> DoubleList;

typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
//typedef Stack<double> DoubleStack;

//typedef Queue<std::string> StringQueue;
//typedef Queue<int> IntQueue;
//typedef Queue<double> DoubleQueue;


#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
typedef std::list<double> DoubleList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
typedef std::stack<double> DoubleStack;
#include <queue>
typedef std::queue<std::string> StringQueque;
typedef std::queue<int> IntQueque;
typedef std::queue<double> DoubleQueue;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	// TODO:
	// Write more tests to fully test your classes.

	StringList a{};
	StringList b{};

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;

	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");

	// TODO: check all methods on StringList...
	StringStack d{};
	StringStack e{};

	d.push("A"); 
        Assert(d.top() == "A", "front == A");
        d.push("B");
        Assert(d.top() == "B", "front == B");
        d.pop();
        Assert(d.top() == "A", "front == A");
        d.push("Z");
        Assert(d.top() == "Z", "front == Z");
	
	StringStack c{};
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "B is not empty");
	c.pop();
	Assert(c.empty() == true, "B is empty");

	// TODO: check all methods on StringStack...

	IntList ia{};
	ia.push_front(5);
	ia.push_front(6);
	Assert(ia.front() == 6, "front is 6");

	// TODO: check all methods on IntList...

	IntStack ic{};
	ic.push(6);
	ic.push(5);
	Assert(ic.top() == 5, "top is 5");

	// TODO: check all methods on IntStack...

	return 0;
}


