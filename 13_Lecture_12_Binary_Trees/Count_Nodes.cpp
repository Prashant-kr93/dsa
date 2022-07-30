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

        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};

BinaryTreeNode<int> *TakeInputLevelWise(){
    int rootData;
    cin>>rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    
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
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChildData);
            pn.push(leftNode);
            front->left = leftNode;
        }
        
        cin>> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChildData);
            front->right = rightNode;
            pn.push(rightNode);
        }
        
    }
    return root;   
}

int numNodes(BinaryTreeNode<int> *root){
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
    
}



int main(){
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    cout<<numNodes(root)<<endl;
}