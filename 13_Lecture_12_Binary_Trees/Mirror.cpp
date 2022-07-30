/*
For a given Binary Tree of type integer, update it with its corresponding mirror image.
Example:
Alt text

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the mirrored tree in a level-wise order. 
Each level will be printed on a new line. Elements printed at each level will be separated by a single line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 
3 2 
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5 
6 10 
3 2 
9
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
            this ->data = data;
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
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

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
            currNode->right = rightNode;
            pn.push(rightNode);

        }
        
        
    }
    return root;    
}


void mirrorBinaryTree(BinaryTreeNode<int>* root){
    if (root == NULL)
    {
        return;
    }

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> *ltemp = root->left;
    BinaryTreeNode<int> *rtemp = root->right;
    root->left= rtemp;
    root->right= ltemp;

    //alternate way
    // if(!root)
    //    return;
    // BinaryTreeNode<int>* temp=root->left;
    
    // root->left=root->right;
    // root->right=temp;
    
    // mirrorBinaryTree(root->left);
    // mirrorBinaryTree(root->right);

}

void PrintLevelWiseAtNewLine(BinaryTreeNode<int>* root){
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    pn.push(NULL); // for breaking line like if root data then only one data print and endl

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


int main(){
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    mirrorBinaryTree(root);
    PrintLevelWiseAtNewLine(root);
}