#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    TrieNode *node[26];
    bool end;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            node[i] = nullptr;
        }
        end = false;
    }
};
class PrefixTree
{

    TrieNode *root;

public:
    PrefixTree()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (curr->node[i] == nullptr)
                curr->node[i] = new TrieNode();
            curr = curr->node[i];
        }
        curr->end = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (curr->node[i] == nullptr)
                return false;
            curr = curr->node[i];
        }
        return curr->end;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (char c : prefix)
        {
            int i = c - 'a';
            if (curr->node[i] == nullptr)
                return false;
            curr = curr->node[i];
        }
        return true;
    }
};
int main()
{
    return 0;
}