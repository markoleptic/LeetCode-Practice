#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static void modifyTailNext(ListNode *head, int pos)
{
	if (pos < 0)
		return;
	ListNode *tailNext = nullptr;

	int index = 0;
	ListNode *current = head;

	// Find the node at position pos
	while (current)
	{
		if (index == pos)
		{
			tailNext = current;
			break;
		}
		current = current->next;
		index++;
	}

	if (pos == 0)
	{
		// If pos is 0, connect the last node to the head
		current = head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = head;
	}
	else if (tailNext)
	{
		// Connect the last node to the node at position pos
		current = head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = tailNext;
	}
}

/**
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note
that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/
class Solution
{
      public:
	bool hasCycle(ListNode *head, int pos)
	{
		modifyTailNext(head, pos);
		if (!head || !head->next)
			return false;
		ListNode *headOne = head;
		ListNode *headTwo = head;
		while (headTwo && headTwo->next)
		{
			headOne = headOne->next;
			headTwo = headTwo->next->next;
			if (headOne == headTwo)
			{
				return true;
			}
		}
		return false;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::hasCycle);
}
#endif