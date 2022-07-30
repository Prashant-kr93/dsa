/*
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.
Output Format:
 The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). 
 Print the elements in increasing order.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10
*/


#include<iostream>
#include <queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left, *right;

        BinaryTreeNode(T data){
            this-> data = data;
            left = right = NULL;
        }
        ~BinaryTreeNode(){
            if (left) delete left;
            if(right) delete right;
        }
};

BinaryTreeNode<int> *takeInputLW(){
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        int leftChildData, rightChildData;
        cin>>leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChildData);
            pn.push(leftNode);
            front->left = leftNode;
        }
        cin>>rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChildData);
            pn.push(rightNode);
            front->right = rightNode;
        }
        
    }
    return root;
}

void printTreeLw_newLine(BinaryTreeNode<int> *root){
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
        if (front->left)
        {
            pn.push(front->left);
        }
        if (front->right)
        {
            pn.push(front->right);
        }
    }
    
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2){
    if ( root == NULL)
    {
        return;
    }
    // if ( root->data >= k1 && root->data <= k2)
    // {
    //     cout<<root->data<<" ";
    // }
    
    if (root->data > k1)
    {
        elementsInRangeK1K2(root->left,k1,k2);
    }

    //increasing order so firstly call on left then print 
    if (root->data >= k1 && root->data <=k2)
    {
        cout<<root->data<<" ";
    }
    

    if (root->data < k2)
    {
        elementsInRangeK1K2(root->right,k1,k2);
    }
    
}

int main(){
    BinaryTreeNode<int> *root = takeInputLW();
    // printTreeLw_newLine(root);
    int k1,k2;
    cin>>k1>>k2;
    elementsInRangeK1K2(root,k1,k2);
    cout<<endl;
}