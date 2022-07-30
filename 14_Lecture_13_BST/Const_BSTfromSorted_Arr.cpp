/*
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 
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
            left = NULL;
            right = NULL;
        }
};

BinaryTreeNode<int> *constructTreeHelper(int *arr, int si, int ei){
    if (si>ei)
    {
        return NULL;
    }
    int mid = (si+ei)/2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int>*leftNode =  constructTreeHelper(arr,si,mid-1);
    BinaryTreeNode<int>* rightNode = constructTreeHelper(arr,mid+1,ei);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n){
    return constructTreeHelper(input,0,n-1);
}

void preOrder(BinaryTreeNode<int> *root){
    if ( root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for ( int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    BinaryTreeNode<int> *root = constructTree(arr,n);
    preOrder(root);
}