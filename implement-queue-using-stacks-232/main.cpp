#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the
functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is
empty operations are valid. Depending on your language, the stack may not be supported natively. You may simulate a
stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

*/
class MyQueue
{
      private:
	stack<int> stack1;
	stack<int> stack2;

      public:
	MyQueue() {}

	void push(int x) 
	{ 
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack1.push(x);
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	int pop()
	{
		int front = stack1.top();
		stack1.pop();
		return front;
	}

	int peek()
	{
		return stack1.top();
	}

	bool empty() {
		return stack1.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
#endif