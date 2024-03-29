/*
You have been given a singly linked list of integers along with an integer 'N'. 
Write a function to append the last 'N' nodes towards the front of the 
singly linked list and returns the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of 
test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the 
elements of the singly linked list separated by a single space. 

The second line contains the integer value 'N'. It denotes the 
number of nodes to be moved from last to the front of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of 
the singly linked list and hence, would never be a list element.

Output format :
For each test case/query, print the resulting singly linked 
list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
0 <= N < M
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
Sample Input 2 :
1
10 6 77 90 61 67 100  -1
4
Sample Output 2 :
90 61 67 100 10 6 77 
 Explanation to Sample Input 2 :
We have been required to move the last 4 nodes to the front of the list. 
Here, "90->61->67->100" is the list which represents the last 4 nodes. 
When we move this list to the front then the remaining part of the 
initial list which is, "10->6->77" is attached after 100. Hence, 
the new list formed with an updated head pointing to 90
*/


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

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else{
            tail ->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(Node*head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head ->next;
    }
    cout<<endl;
}

int lengthLL(Node* head){
    if (head == NULL)
    {
        return 0;
    }
    return 1 + lengthLL(head->next);
}

Node *appendLastNToFirst(Node*head, int n)
{
    int l = lengthLL(head);
    Node *temp = head;
    Node *tail = head;
    int i =0;
    //first reach to the pointer whose next become head for final 
    while (i < (l-n-1) && temp != NULL)
    {
        temp = temp->next;
        tail = tail ->next; // increase ponter for finding tail
        i++;
    }
    while (i< l-1 && tail != NULL) // find tail of old ll
    {
        tail = tail ->next;
        i++;
    }

    tail->next = head; // attach original head to tail of orginal LL
    head = temp->next;

    //Deleteing the previous connection
    temp->next = NULL;
    return head;


    // int l = lengthLL(head);
    // Node * temp = head;
    // Node* tail = head;
    // int i = 0;
    // while (i<l-n-1 && temp!= NULL)
    // {
    //     temp = temp->next;
    //     tail = tail->next;
    //     i++;
    // }
    // while (i<l-1 && tail != NULL)
    // {
    //     tail = tail->next;
    //     i++;
    // }
    // tail->next = head;
    // head = temp->next;

    // //Deleting the previous connection
    // temp->next = NULL;
    // return head;


    
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        Node * head = takeInput();
        // print(head);
        // cout<<lengthLL(head)<<endl;
        int n;
        cin>>n;
        head = appendLastNToFirst(head,n);
        print(head);
    }
    
}