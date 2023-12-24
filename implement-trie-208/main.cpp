#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a
dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false
otherwise.
	boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the
prefix prefix, and false otherwise.

*/
class Trie
{
      private:
	map<char, Trie *> children;
	char value;
	bool bIsTerminal = false;

      public:
	Trie() {}

	void insert(string word)
	{
		Trie *node = this;
		for (int i = 0; i < word.length(); ++i)
		{
			if (!node->children[word[i]])
			{
				node->children[word[i]] = new Trie();
			}
			node = node->children[word[i]];
		}
		node->bIsTerminal = true;
	}

	bool search(string word)
	{
		Trie *node = this;
		for (int i = 0; i < word.length(); ++i)
		{
			if (!node->children[word[i]])
				return false;
			node = node->children[word[i]];
		}
		if (!node->bIsTerminal)
			return false;
		return true;
	}

	bool startsWith(string prefix)
	{
		Trie *node = this;
		for (int i = 0; i < prefix.length(); ++i)
		{
			if (!node->children[prefix[i]])
				return false;
			node = node->children[prefix[i]];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Trie::insert);
}
#endif