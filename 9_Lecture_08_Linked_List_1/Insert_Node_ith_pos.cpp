#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node * temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


//Recursively
Node *insert(Node *head, int pos,int data){
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        Node* temp = head;
        head = newNode;
        head->next = temp;
        return head;
    }
    Node *smallAns = insert(head->next,pos-1,data);
    head->next = smallAns;
    return head;
}

Node* insertNode(Node* head,int pos, int data){
    Node *newNode = new Node(data);
    Node* temp = head;
    int i = 0;
    if (pos == 0)
    {
        head = newNode;
        head->next = temp;
        return head;
    }
    
    while (temp != NULL && i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
    {
        Node* a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
}


int main(){
    int t;
    cin>>t;
    while (t--)
    {
        Node* head = takeInput();
        // print(head);
        int pos,data;
        cin>>pos>>data;
        // head = insertNode(head,pos,data);
        head = insert(head,pos,data);
        print(head);
    }
    
}