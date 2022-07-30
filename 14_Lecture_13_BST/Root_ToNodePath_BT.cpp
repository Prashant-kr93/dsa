#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left, *right;

        BinaryTreeNode(T data){
            this->data = data;
            left = right = NULL;
        }
        ~BinaryTreeNode(){
            if ( left)
            {
                delete left;
            }
            if(right) delete right;
        }
};

BinaryTreeNode<int>* takeInputLW(){
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while (pn.size() != 0)
    {
        BinaryTreeNode<int>* front = pn.front();
        pn.pop();
        int leftData,rightData;
        cin>>leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
            pn.push(leftNode);
            front->left = leftNode;
        }
        cin>>rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
            pn.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
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
        BinaryTreeNode<int>* front = pn.front();
        pn.pop();
        if (front == NULL)
        {
            if (pn.size() ==0)
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

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root,int data){
    if ( root == NULL)
    {
        return NULL;
    }
    if ( root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left,data);
    if (leftOutput)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right,data);
    if (rightOutput)
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
    printLW_newLine(root);
    int k;
    cin>>k;
    vector<int> *output = getRootToNodePath(root,k);
    for (int i = 0; i < output->size(); i++)
    {
        cout<<output->at(i)<<" ";
    }
    delete root;
}