#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
class Solution
{
      public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *previous = nullptr;
		ListNode *current = head;
		while (current)
		{
			ListNode *next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		return previous;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::reverseList);
}
#endif