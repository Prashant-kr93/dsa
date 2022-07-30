#include<iostream>
#include<queue>
using namespace std;


template<typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left, *right;

        BinaryTreeNode(T data){
            this-> data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

BinaryTreeNode<int> *buildTreeHelper(int*in, int *post, int inS, int inE,int postS, int postE){
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = post[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
        }
        
    }
    int leftInS = inS;
    int leftInE = rootIndex-1;
    int leftPostS = postS;
    int leftPostE = (leftInE-leftInS) +leftPostS; // use eqn : length of left in inOrder = length of left in postOrder
                                                            //          leftInE- leftInS = leftPostE - leftPostS

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPostS = leftPostE+ 1;
    // int rightPostE = (rightInE-rightInS) + rightPostS;
    int rightPostE = postE - 1;
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in,post,leftInS,leftInE,leftPostS,leftPostE);
    root->right = buildTreeHelper(in, post,rightInS, rightInE,rightPostS,rightPostE);
    return root;
    
    
}

BinaryTreeNode<int>* buildTree(int *post, int postLength,int *in, int inLength){
    return buildTreeHelper(in, post,0,inLength-1,0,postLength-1);
}

void printLW_AtNewLine(BinaryTreeNode<int> *root){
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
        if (front->left != NULL)
        {
            pn.push(front->left);
        }
        if (front->right != NULL)
        {
            pn.push(front->right);
        }
        
    }
    
}

int main(){
    int n;
    cin>>n;
    int *post = new int[n];
    int *in = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>post[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    BinaryTreeNode<int> *root = buildTree(post,n,in,n);
    printLW_AtNewLine(root);
    
}