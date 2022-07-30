/*
// For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
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
        this->data = data;
        left = right = NULL;
    }
};

BinaryTreeNode<int> *takeInputLW(){
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
        int leftData;
        cin>>leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftData);
            pn.push(leftNode);
            front->left = leftNode;
        }
        int rightData;
        cin>>rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightData);
            pn.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root){
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        cout<<front->data<<":";
        if ( front->left != NULL)
        {
            BinaryTreeNode<int>*left = front->left;
            cout<<"L:"<<left->data<<",";
            pn.push(left);
        }
        else{
            cout<<"L:"<<-1<<" ";
        }

        if (front->right != NULL)
        {
            cout<<"R:"<<front->right->data;
            pn.push(front->right);
        }
        else{
            cout<<"R:"<<-1;
        }
        cout<<endl;
    }
    
    
}

void printLW_newLine(BinaryTreeNode<int>*root){
    if (root == NULL)
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

BinaryTreeNode<int> *buildTreeHelper(int *in,int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    
    int rootElement = pre[preS];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootElement);
    
    //Find rootIndex
    int rootIndex = 0;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootElement)
        {
            rootIndex = i;
            break;
        }
        
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPreS = preS + 1;
    int lengthLeft = leftInE- leftInS;
    int leftPreE = lengthLeft + leftPreS;// since no. of node in left is same so use that eqn: leftInE - leftInS = leftPreE - leftPreS
                                                                                            //  => leftPreE = (leftInE - leftIns) + leftPreS

    int rightInS = rootIndex +1;
    int rightInE = inE;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    
    root->left = buildTreeHelper(in, pre,leftInS, leftInE, leftPreS, leftPreE);
    root->right = buildTreeHelper(in, pre, rightInS, rightInE, rightPreS, rightPreE);
    return root;

}



BinaryTreeNode<int>* buildTree(int* pre, int preLength, int*in, int inLength){
    return buildTreeHelper(in, pre,0,inLength-1,0,preLength-1 );
}


int main(){
    // BinaryTreeNode<int> *root = takeInputLW();
    // printLevelWise(root);
    int length;
    cin>>length;
    int *pre = new int[length];
    int *in = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin>>pre[i];
    }
    for (int i = 0; i < length; i++)
    {
        cin>>in[i];
    }

    BinaryTreeNode<int> *root = buildTree(pre,length,in,length);      
    printLW_newLine(root);
}