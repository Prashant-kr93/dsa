#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* *children;
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            children = new TrieNode*[26];
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    TrieNode* root;
    public:
        Trie(){
            root = new TrieNode('\0');
        }

        void insertWord(string word){
            if (word.size() == 0)
            {
                if (!root->isTerminal)
                {
                    root->isTerminal = true;
                    return ;
                }
                
            }
            
            int index = word[0] - 'a';
            TrieNode* child;
            if (root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            
        }

};

int main(){
    int n;
    cin>>n;
    vector<string> input;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        input.push_back(s);
    }
    string pattern;
    cin>>pattern;
}