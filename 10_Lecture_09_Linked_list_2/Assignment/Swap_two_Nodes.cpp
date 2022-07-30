#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;

    }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
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
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *swap_2_Node(Node* head, int m, int n){
    Node *temp = head;
    int i = 0;
    for (; i < m-1; i++)
    {
        temp = temp->next;
    }
    Node *fp = temp;
    temp = temp->next;
    i++;
    Node *f = temp;

    temp = temp->next;
    i++;
    Node *fn = temp;

    // temp = temp->next;
    // i++;
    fp->next = f->next = NULL;


    
    for ( ; i < n-1; i++)
    {
        temp = temp->next;
    }
    Node* sp = temp;

    temp=temp->next;
    i++;
    Node *s = temp;

    temp= temp->next;
    i++;
    Node* sn = temp;
    sp->next = s->next = NULL;
    fp->next = s;
    s->next = fn;
    sp->next = f;
    f->next = sn;

    return head;

}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        Node *head = takeInput();
        print(head);
        int i,j;
        cin>>i>>j;
        head = swap_2_Node(head, i,j);
        print(head);
    }
    
}