#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

	MinStack() initializes the stack object.
	void push(int val) pushes the element val onto the stack.
	void pop() removes the element on the top of the stack.
	int top() gets the top element of the stack.
	int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
*/
class MinStack
{
public:
	stack<int> data;
	stack<int> min;
	MinStack() {}

	void push(int val)
	{
		if (min.empty() || min.top() >= val)
			min.push(val);
		data.push(val);
	}

	void pop()
	{
		if (data.empty())
			return;
		if (!min.empty() && data.top() == min.top())
			min.pop();
		data.pop();
	}

	int top() { return data.top(); }

	int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&MinStack::push);
}
#endif