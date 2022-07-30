#include<iostream>
#include<queue>
#include<vector>
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
};

BinaryTreeNode<int>* takeInputLW(){
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while (pn.size() != 0)
    {
        BinaryTreeNode<int>* front = pn.front();
        pn.pop();
        int leftData,rightData;
        cin>>leftData>>rightData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftData);
            pn.push(leftNode);
            front->left = leftNode;
        }
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightData);
            pn.push(rightNode);
            front->right = rightNode;
        }
        
    }
    return root;
}

vector<int>* getPath(BinaryTreeNode<int>*root, int data){
    if (root == NULL)
    {
        return NULL;
    }
    if ( root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getPath(root->left,data);
    if (leftOutput)
    {
        leftOutput->push_back(root->data);
        return  leftOutput;
    }
    
    vector<int> *rightOutput = getPath(root->right,data);
    if ( rightOutput)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
    
}

int main(){
    BinaryTreeNode<int> *root = takeInputLW();
    int data;
    cin>>data;
    vector<int>* output = getPath(root, data);
    for (int i = 0; i < output->size(); i++)
    {
        cout<<output->at(i)<<" ";
    }
    cout<<endl;
    delete output;
}