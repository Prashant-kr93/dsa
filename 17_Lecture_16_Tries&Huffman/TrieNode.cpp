#include<iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode** children;
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];// maxm 26 alphabet character
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        
        isTerminal = false;
    }   

    ~TrieNode(){
        for (int i = 0; i < 26; i++)
        {
            delete children[i];
        }
        delete[] children;
    }

};  

