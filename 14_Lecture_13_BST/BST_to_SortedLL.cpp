/*
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/


#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data){
            this->data = data;
            left = right = NULL;
        }

        ~BinaryTreeNode(){
            if ( left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
            
        }
};

template<typename T>
class Node{
    public:
        T data;
        Node<T> *next;

        Node(T data){
            this->data = data;
            this->next = NULL;
        }
};

BinaryTreeNode<int> *takeInputLw(){
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        int leftData,rightData;
        cin>>leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftData);
            front->left = leftNode;
            pn.push(leftNode);
        }
        cin>>rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightData);
            front->right = rightNode;
            pn.push(rightNode);
        }
        
    }
    return root;
}

class BasePair{
    public:
        Node<int> *head;
        Node<int> *tail;

        BasePair(){
            head = NULL;
            tail = NULL;
        }
};


BasePair constructLL_helper(BinaryTreeNode<int> *root){
    BasePair finalLL;
    if (root == NULL)
    {
       return finalLL;
    }
    BasePair leftP = constructLL_helper(root->left);
    BasePair rightP = constructLL_helper(root->right);
    Node<int> *newNode = new Node<int>(root->data);

    if (leftP.tail != NULL)
    {
        leftP.tail->next = newNode;
    }
    
    newNode->next = rightP.head;
    if (leftP.head != NULL)
    {
        finalLL.head = leftP.head;
    }
    else{
        finalLL.head = newNode;
    }
    
    if (rightP.tail != NULL)
    {
        finalLL.tail = rightP.tail;
    }
    else{
        finalLL.tail = newNode;
    }
    
    return finalLL;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root){
    return constructLL_helper(root).head;
}

void printLW_newLine(BinaryTreeNode<int> *root){
    if ( root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    pn.push(NULL);
    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        if (front == NULL)
        {
            if (pn.size() == 0)
            {
                break;
            }
            
            cout<<endl;
            pn.push(NULL);
            continue;
        }
        
        cout<<front->data<<" ";
        if ( front ->left)
        {
            pn.push(front->left);
        }
        if ( front->right)
        {
            pn.push(front->right);
        }
        
    }
    cout<<endl;
}

void printLL(Node<int>* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
}

int main(){
    BinaryTreeNode<int>*root = takeInputLw();
    printLW_newLine(root);

    Node<int> *head = constructLinkedList(root);
    printLL(head);
}