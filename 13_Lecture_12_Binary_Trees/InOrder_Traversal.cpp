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
            pn.push(rightNode);
            currNode->right = rightNode;
        }
        
    }
    return root;
}

void inorder(BinaryTreeNode<int> *root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    inorder(root);
    return 0;
}
