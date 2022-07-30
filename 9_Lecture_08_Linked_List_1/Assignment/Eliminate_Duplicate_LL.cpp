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
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(Node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node *removeDuplicates(Node* head){
    //Recursively
    if (head == NULL)
    {
        return head;
    }
    Node *small = removeDuplicates(head->next);
    if (small != NULL && head->data == small->data)
    {
        head->next= small->next;
    }
    return head;

    //Iteratively
    // //temp pointing to head
    // if(head==NULL){
    //     return head;
    // }
	// Node *temp = head;            
	// while(temp->next != NULL && temp != NULL){
	// 	//Duplicate Found
	// 	if(temp->data == temp->next->data){      
	// 		//DUplicate Removed
	// 		temp -> next = temp ->next ->next;    
	// 	}
	// 	else{
	// 		//No Duplicate Present
	// 		temp = temp->next;               
	// 	}
	// }
	// //Return Head
	// return head;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        Node* head = takeInput();
        print(head);
        head = removeDuplicates(head);
        print(head);

    }
    
}