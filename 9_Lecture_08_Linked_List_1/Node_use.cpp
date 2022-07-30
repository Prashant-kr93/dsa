#include<iostream>
using namespace std;
#include "Node.cpp"

Node* input(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
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
            tail = newNode; // or tail = tail->next;
        }
        cin>>data;
    }
    return head;
}


//Bad approach t.complextiy = O(n^2)
Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    while (data != -1)
    {
        // Node n(data);// if we create statically then it will delete for always after every entering new data(or iteration).

        Node *newNode = new Node(data);// always create dynamically
        if (head == NULL)
        {
            head = newNode;
        }
        else{
            // head->next = newNode;// this every time linked head with new node and all previous lost so 
                                 // so this way is wrong.

            //So we have to travel from head node to last node to link any new node
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin>>data;
    }
    return head;
}

void print(Node* head){
    // while (head->next != NULL) // this will go for only n-1 because last node(tail) has head->next = NULL 
                                 // so it can't go under loop if use this so new condn is head != NULL.

    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// void print(Node *head){
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<endl;
//     temp  = head;
//     while (temp != NULL)
//     {
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout <<endl;
// }

int main(){
    // Node n1(1);
    // Node *head = &n1;

    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // Node* head = takeInput();
    Node *head = input();
    print(head);
    print(head);
}