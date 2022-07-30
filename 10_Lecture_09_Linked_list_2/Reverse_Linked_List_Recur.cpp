#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node( int data){
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
        Node * newNode = new Node(data);
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

void print(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// O(n^2)- bad approach
Node* reverseLL_1(Node* head){
    if (head == NULL || head ->next == NULL)
    {
        return head;
    }
    Node *smallAns = reverseLL_1(head->next);
    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp ->next;
    }
    temp->next = head;

    //V.V.I step
    head->next = NULL;
    return smallAns;

}

/*************************************************************************/
//Double Node method- O(n)
class Pair{
    public:
    Node *head;
    Node *tail;
};

Pair reverseLL_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = ans.tail= head;
        return ans;
    }
    Pair smallans = reverseLL_2(head->next);
    Pair ans;
    smallans.tail->next = head;
    head->next = NULL;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}

Node *reverseLL_Better(Node * head){
    return reverseLL_2(head).head;
}

/*************************************************************************/


//Best approach - O(n):
Node *reverseLL_Best(Node *head){
    if (head == NULL || head ->next == NULL)
    {
        return head;
    }
    Node* ans = reverseLL_Best(head ->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        Node *head = takeInput();
        print(head);
        // head = reverseLL_1(head);
        // head  = reverseLL_Better(head);
        head = reverseLL_Best(head);
        print(head);
    }
    
}