#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

struct TrieNode
{
    bool isWord;
    unordered_map<char, TrieNode *> children;
    TrieNode(void) { isWord = false; }
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
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isWord = true;
    }

    bool search(const string &word, bool isWord = true)
    {
        TrieNode *current = root;
        for (auto &&ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return isWord ? current->isWord : true;
    }
};

int main(void)
{
    Trie myTrie;
    int count;
    string str;
    bool flag;
    cout << "Enter the number of strings you want to add: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter the word: ";
        cin >> str;
        myTrie.insertWord(str);
    }

    cout << "Enter the number of operations you want to perform: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter the query as (word isWord): ";
        cin >> str >> flag;
        cout << boolalpha << myTrie.search(str, flag) << '\n';
    }
    return 0;
}