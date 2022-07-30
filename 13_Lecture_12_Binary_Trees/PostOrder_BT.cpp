/*
For a given Binary Tree of integers, print the post-order traversal.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the post-order traversal of the given binary tree.
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
4 5 2 6 7 3 1 
Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 Sample Output 1:
2 9 3 6 10 5 
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
            delete left;
            delete right;
        }

};

BinaryTreeNode<int> *TakeInputLevelWise(){
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *currNode = pn.front();
        pn.pop();
        int leftChild, rightChild;

        cin>>leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            pn.push(leftNode);
            currNode->left = leftNode;
        }

        cin>>rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            pn.push(rightNode);
            currNode->right = rightNode;
        }
        
        
    }
    return root;
}

void postOrder(BinaryTreeNode<int> *root){
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    postOrder(root);
}