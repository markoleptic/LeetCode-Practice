#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int newVal) { val = newVal; }
	TreeNode(int newVal, TreeNode *newLeft, TreeNode *newRight)
	{
		val = newVal;
		left = newLeft;
		right = newRight;
	}
};
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(-1), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

template <typename T> struct is_bitset : public false_type
{
};
template <size_t N> struct is_bitset<bitset<N>> : public true_type
{
};
template <typename T, typename = void> struct is_iterable : public false_type
{
};
template <typename T>
struct is_iterable<T, void_t<decltype(begin(declval<T &>())), decltype(end(declval<T &>()))>> : public true_type
{
};
template <typename T, typename = void> struct is_tuple_like : public false_type
{
};
template <typename T> struct is_tuple_like<T, void_t<typename tuple_size<T>::type>> : public true_type
{
};
template <typename = void> inline constexpr bool always_false = false;

template <typename T> void _print(const T &x)
{
	if constexpr (is_same_v<T, bool>)
	{
		cout << (x ? "true" : "false");
	}
	else if constexpr (is_arithmetic_v<T>)
	{
		cout << x;
	}
	else if constexpr (is_same_v<T, string> || is_bitset<T>::value)
	{
		cout << '\"' << x << '\"';
	}
	else if constexpr (is_tuple_like<T>::value)
	{
		cout << '{';
		int c = 0;
		auto f = [&](auto &&... args) { ((cout << (c++ ? "," : ""), _print(args)), ...); };
		apply(f, x);
		cout << '}';
	}
	else if constexpr (is_iterable<T>::value)
	{
		cout << '[';
		int c = 0;
		for (const auto &e : x)
		{
			cout << (c++ ? "," : "");
			_print(e);
		}
		cout << ']';
	}
	else
	{
		static_assert(always_false<T>, "printing for type not supported");
	}
}

#define CONCAT_IMPL(x, y) x##y
#define CONCAT(x, y) CONCAT_IMPL(x, y)
#define NUM_ARGS_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define NUM_ARGS(...) NUM_ARGS_IMPL(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define DBG_VAL(x) cout << '[' << #x << " = ", _print(x), cout << "] "
#define DBG_1(x) DBG_VAL(x)
#define DBG_2(x, ...) DBG_VAL(x), DBG_1(__VA_ARGS__)
#define DBG_3(x, ...) DBG_VAL(x), DBG_2(__VA_ARGS__)
#define DBG_4(x, ...) DBG_VAL(x), DBG_3(__VA_ARGS__)
#define DBG_5(x, ...) DBG_VAL(x), DBG_4(__VA_ARGS__)
#define DBG_6(x, ...) DBG_VAL(x), DBG_5(__VA_ARGS__)
#define DBG_7(x, ...) DBG_VAL(x), DBG_6(__VA_ARGS__)
#define DBG_8(x, ...) DBG_VAL(x), DBG_7(__VA_ARGS__)
#define DBG_9(x, ...) DBG_VAL(x), DBG_8(__VA_ARGS__)
#define DBG_10(x, ...) DBG_VAL(x), DBG_9(__VA_ARGS__)
#define dbg(...) CONCAT(DBG_, NUM_ARGS(__VA_ARGS__))(__VA_ARGS__), cout << endl
// supports up to 10 arguments debugging at one time

template <typename T> T parse(FILE *f)
{
	int c = 0;
	T ans{};
	if constexpr (is_same_v<T, char>)
	{
		fgetc(f);
		ans = (c = fgetc(f));
		fgetc(f);
	}
	else if constexpr (is_integral_v<T>)
	{
		int neg = 0;
		while (((c = fgetc(f)) >= '0' && c <= '9') || c == '-')
		{
			if (c == '-')
				neg = 1;
			else
				ans = ans * 10 + (c - '0') * (1 - 2 * neg);
		}
		ungetc(c, f);
	}
	else if constexpr (is_same_v<T, string>)
	{
		fgetc(f);
		while ((c = fgetc(f)) != '"')
			ans += (char)c;
	}
	else if constexpr (is_same_v<T, TreeNode *>)
	{
		int e = 2;
		auto dummy = new TreeNode{};
		deque<TreeNode *> q;
		q.push_back(dummy);
		fgetc(f);
		while (c != ']')
		{
			int sz = q.size();
			while (sz > 0 && c != ']')
			{
				int val = 0, neg = 0;
				bool is_null = false;
				while ((c = fgetc(f)) != ',' && c != ']')
				{
					if (c >= '0' && c <= '9')
						val = val * 10 + (c - '0') * (1 - 2 * neg);
					else if (c == '-')
						neg = 1;
					else
						is_null = true;
				}
				if (!is_null)
				{
					auto new_node = new TreeNode{val};
					if (e & 1)
						q[0]->left = new_node;
					else
						q[0]->right = new_node;
					q.push_back(new_node);
				}
				if (e++ % 2 == 0)
				{
					q.pop_front();
					sz--;
				}
			}
			e = 1;
		}
		ans = dummy->right;
	}
	else if constexpr (is_same_v<T, ListNode *>)
	{
		auto dummy = new ListNode{};
		auto cur = dummy;
		fgetc(f);
		if ((c = fgetc(f)) != ']')
		{
			ungetc(c, f);
			while (c != ']')
			{
				cur->next = new ListNode{parse<int>(f)};
				cur = cur->next;
				c = fgetc(f);
			}
		}
		ans = dummy->next;
	}
	else if constexpr (is_iterable<T>::value)
	{
		fgetc(f);
		if ((c = fgetc(f)) != ']')
		{
			ungetc(c, f);
			while (c != ']')
			{
				if (!isspace(c = fgetc(f)))
					ungetc(c, f);
				ans.emplace_back(parse<typename T::value_type>(f));
				c = fgetc(f);
			}
		}
	}
	else
		static_assert(always_false<T>, "parsing for type not supported");
	if ((c = fgetc(f)) != '\n')
		ungetc(c, f);
	return ans;
}

template <bool WriteEnd, typename T> void write(FILE *f, const T &val)
{
	static constexpr const char *end = WriteEnd ? "\n" : "";
	if constexpr (is_same_v<T, int>)
		fprintf(f, "%d%s", val, end);
	else if constexpr (is_same_v<T, float>)
		fprintf(f, "%.f%s", val, end);
	else if constexpr (is_same_v<T, double>)
		fprintf(f, "%.18f%s", val, end);
	else if constexpr (is_same_v<T, long long>)
		fprintf(f, "%lld%s", val, end);
	else if constexpr (is_same_v<T, bool>)
		fprintf(f, "%s%s", val ? "true" : "false", end);
	else if constexpr (is_same_v<T, string>)
		fprintf(f, "\"%s\"%s", val.data(), end);
	else if constexpr (is_same_v<T, TreeNode *>)
	{
		deque<TreeNode *> q;
		fprintf(f, "[");
		if (val)
		{
			q.push_back(val);
			fprintf(f, "%d", val->val);
		}
		while (!q.empty())
		{
			int sz = q.size();
			string ans;
			while (sz-- > 0)
			{
				auto cur = q.front();
				q.pop_front();
				if (cur->left)
				{
					q.push_back(cur->left);
					ans += ',';
					ans += to_string(cur->left->val);
				}
				else
					ans += ",null";
				if (cur->right)
				{
					q.push_back(cur->right);
					ans += ',';
					ans += to_string(cur->right->val);
				}
				else
					ans += ",null";
			}
			if (!q.empty())
				fprintf(f, ans.data());
		}
		fprintf(f, "]%s", end);
	}
	else if constexpr (is_same_v<T, ListNode *>)
	{
		int c = 0;
		auto cur = val;
		fprintf(f, "[");
		while (cur)
		{
			fprintf(f, "%s%d", c++ ? "," : "", cur->val);
			cur = cur->next;
		}
		fprintf(f, "]%s", end);
	}
	else if constexpr (is_iterable<T>::value)
	{
		fprintf(f, "[");
		int c = 0;
		for (int i = 0; i < (int)val.size(); i++)
		{
			fprintf(f, "%s", c++ ? "," : "");
			write<false>(f, val[i]);
		}
		fprintf(f, "]%s", end);
	}
	else
		static_assert(always_false<T>, "writing for type not supported");
}

template <typename Args, size_t... Idx> void write_args(FILE *f, const Args &args, index_sequence<Idx...>)
{
	((fprintf(f, "#%lld: ", Idx + 1), write<true>(f, get<Idx + 1>(args))), ...);
}

template <typename Solution, typename R, typename... Ts> void exec(R (Solution::*fn)(Ts...))
{
	constexpr bool returns = !is_same_v<R, void>;
	auto out = fopen("output.txt", "w");
	long long total_elapsed = 0;
	if constexpr (sizeof...(Ts) == 0)
	{
		if constexpr (returns)
		{
			write<true>(out, (Solution{}.*fn)());
		}
		else
			(Solution{}.*fn)();
	}
	else
	{
		auto in = fopen("input.txt", "r");
		int c = 0;
		while (true)
		{
			if ((c = fgetc(in)) == EOF)
				break;
			if (c == '/')
			{
				while ((c = fgetc(in)) != '\n' && c != EOF)
				{
				}
			}
			else
			{
				ungetc(c, in);
				tuple args{Solution{}, parse<decay_t<Ts>>(in)...};
				long long elapsed = 0;
				if constexpr (!returns)
				{
					auto start = chrono::steady_clock::now();
					apply(fn, args);
					auto end = chrono::steady_clock::now();
					elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
					fprintf(out, "New state of parameters:\n");
					write_args(out, args, index_sequence_for<Ts...>{});
				}
				else
				{
					auto start = chrono::steady_clock::now();
					auto res = apply(fn, args);
					auto end = chrono::steady_clock::now();
					elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
					write<true>(out, res);
				}
				total_elapsed += elapsed;
				fprintf(out, "Elapsed time: %lldms\n", elapsed);
				printf("\n"); // separate debug calls of test cases
			}
		}
		fclose(in);
	}
	fprintf(out, "\nTotal elapsed time: %lldms", total_elapsed);
	fclose(out);
}
