/*
For a given singly linked list of integers, arrange the elements such that 
all the even numbers are placed after the odd numbers. 
The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. 
Only return the new head to the list.

Input format:
The first line contains an Integer 't' which denotes the number of test cases 
or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements 
of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of 
the singly linked list and hence, would never be a list element

Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 4 5 2 -1

Sample Output 1 :
1 5 4 2

Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1

Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40

*/


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this ->data = data;
        this ->next = NULL;

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
            tail = tail->next;

        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node *even_After_Odd(Node* head){
    Node *oddH = NULL, *oddT = NULL;
    Node *evenH = NULL, *evenT = NULL;
    while (head != NULL)
    {
        if (head ->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenH = evenT = head;
            }
            else{
                evenT ->next = head;
                evenT = evenT->next;
            }
            head = head->next;
        }
        else{
            if (oddH == NULL)
            {
                oddH = oddT = head;
            }
            else{
                oddT->next = head;
                oddT = oddT->next;
            }
            head = head->next;
        }
    }

    if (oddH == NULL)
    {
        evenT->next = NULL;
        return evenH;
    }
    else{
        if (evenH == NULL)
        {
            return oddH;
        }
        evenT->next = NULL;
        oddT ->next = NULL;
        oddT ->next = evenH;
        return oddH;
    }
    

}

Node *EvenAfterOdd(Node *head){
    if (head == NULL || head ->next == NULL)
    {
        return head;
    }
    Node *smallAns = EvenAfterOdd(head->next);
    if (head->data % 2 != 0)
    {
        head->next = smallAns;
        return head;
    }
    else if(head->data % 2 == 0){
        Node *temp = smallAns;
        while ( temp != NULL && temp->data % 2 != 0)
        {
            Node* t = temp->next;
            if (t != NULL && t->data % 2 == 0 )
            {
                temp->next = head;
                head->next = t;
                return smallAns;
            }
            temp = temp->next;
        }
        
    }
}


int main(){
    int t;
    cin>>t;
    while (t--)
    {
        Node *head = takeInput();
        print(head);
        // head = EvenAfterOdd(head);
        head = even_After_Odd(head);
        print(head);
    }
    
}