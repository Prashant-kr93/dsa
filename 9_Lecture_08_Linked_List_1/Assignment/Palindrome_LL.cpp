#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = NULL; 
    Node *tail = NULL;
    while (data != -1)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

int lengthLL(Node* head){
    if (head == NULL)
    {
        return 0;
    }
    return 1 + lengthLL(head->next);
}

Node* reverse(Node* head){
    
}

bool isPalindrome(Node* head){
    
    


    // bool smallans = isPalindrome(head->next);
    // if (smallans)
    // {
    //     Node* temp = head;
    //     int l = lengthLL(head);
    //     int i = 0;
    //     while (i<l-1)
    //     {
    //         temp = temp->next;
    //     }
    //     if (head->data == temp->data)
    //     {
    //         return true;
    //     }
        
    // }
    
    
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        Node *head = takeInput();
        bool ans = isPalindrome(head);
        if (ans)
        {
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
    
}