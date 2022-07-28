#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    bool isWord;
    long long int count_words;
    unordered_map<char, TrieNode *> children;
    TrieNode(void)
    {
        isWord = false;
        count_words = 0;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie(void) : root(new TrieNode()) {}

    void insertWord(const string &word)
    {
        TrieNode *current = root;
        for (auto &&ch : word)
        {
            current->count_words++;
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isWord = true;
        current->count_words++;
    }

    long long int search(const string &word, bool isWord = true)
    {
        TrieNode *current = root;
        long long int count = -current->count_words;
        for (auto &&ch : word)
        {
            count += current->count_words;
            if (!current->children[ch])
                return count;
            current = current->children[ch];
        }
        return count += current->count_words;
    }
};

int main(void)
{
    Trie t;
    vector<string> s = {"abd", "bcd", "abc"};
    for (auto &&str : s)
        t.insertWord(str);

    for (auto &&str : s)
    {
        cout << t.search(str) << '\n';
    }
    return 0;
}