#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // small calculation
        int indexOfChar = word[0] - 'a';
        TrieNode *child;                         // new root for recursive call
        if (root->children[indexOfChar] != NULL) // means that char is present in children of root
        {
            child = root->children[indexOfChar];
        }
        else
        { // create new TrieNode and connect them to children of root
            child = new TrieNode(word[0]);
            root->children[indexOfChar] = child;
        }

        // recursive call;
        insertWord(child, word.substr(1)); // for recursive call we need new root (as root of subtree) so in
                                           // this function we have to must pass newroot(as child) for recursive call
                                           // but for user they have no idea of root so we have to make this function as helper fun
                                           // And make another fun for user
    }

    // For user
public:
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    // for searching also need root for recursive call
    // so make helper function
// private:
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            // if (root->isTerminal)
            // {
            //     return true;
            // }
            // else
            //     return false;
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            // return true;
        }
        else
        {
            return false;
        }

        return search(child, word.substr(1));
    }

public:
    bool search(string word)
    {
        return search(root, word);
    }


    //helper function for removeWord
    void removeWord(TrieNode* root, string word){
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            return;
        }
        // if (child == NULL)
        // {
        //     return;
        // }
        removeWord(child,word.substr(1));

        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
               if(child->children[i]  != NULL){
                   return;
               }
            }
            delete child;
            root->children[index] = NULL;
        }
        
    }

    void removeWord(string word){
        removeWord(root,word);
    }
};

int main()
{
    int choice;
    cin >> choice;

    Trie t;
    while (choice != -1)
    {
        string word;
        bool ans;
        switch (choice)
        {
        case 1: // insertion
            cin >> word;
            t.insertWord(word);
            break;
        case 2: // searching
            cin >> word;
            cout << (t.search(word) ? "true" : "false") << endl;
            break;
        case 3:
            cin>>word;
            t.removeWord(word);
            break;
        default:
            break;
        }
        cin >> choice;
    }
    return 0;
}