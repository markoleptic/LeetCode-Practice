#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

*/
const vector<string> ops = {"+", "-", "*", "/"};

class Solution
{
      public:
	int evalRPN(vector<string> &tokens)
	{
		stack<int> operands;
		int result = 0;
		for (string str : tokens)
		{
			auto found = find(ops.begin(), ops.end(), str);
			if (found == ops.end())
			{
				operands.push(atoi(str.c_str()));
			}
			else
			{
				if (!operands.empty())
				{
					int right = operands.top();
					operands.pop();
					int left = operands.top();
					operands.pop();

					if (str == ops[0])
						result = (left + right);
					else if (str == ops[1])
						result = (left - right);
					else if (str == ops[2])
						result = (left * right);
					else
						result = (left / right);
					cout << left << " " << str << " " << right << " " << result << endl;
					operands.push(result);
				}
			}
		}
		if (!operands.empty())
			return operands.top();
		return result;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::evalRPN);
}
#endif