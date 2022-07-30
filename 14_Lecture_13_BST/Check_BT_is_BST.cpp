#include <iostream>
#include <queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

BinaryTreeNode<int> *takeInputLW()
{
    int rootData;
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pn;
    pn.push(root);

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            pn.push(leftNode);
            front->left = leftNode;
        }
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            pn.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

void printBT_LW_newLine(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pn;
    pn.push(root);
    pn.push(NULL);
    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        if ( front == NULL)
        {
            if (pn.size() == 0)
            {
                break;
            }
            pn.push(NULL);
            cout<<endl;
            continue;
        }
        
        cout << front->data << " ";
        if (front->left)
        {
            pn.push(front->left);
        }
        if (front->right)
        {
            pn.push(front->right);
        }
    }
    cout<<endl;
}



//Approach 1: O(n*h)
int minimum(BinaryTreeNode<int>*root){
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));

}

int maximum(BinaryTreeNode<int>*root){
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST1(BinaryTreeNode<int> *root){
    if ( root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    return (root->data > leftMax) && (root->data <= rightMin) && isBST1(root->left) && isBST1(root->right);

}




//Approach 2: O(n)
class BSTReturn{
    public:
        bool isBST;
        int minimum;
        int maximum;
};

BSTReturn isBST2(BinaryTreeNode<int> *root){
    if (root == NULL)
    {
        BSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    BSTReturn leftOutput = isBST2(root->left);
    BSTReturn rightOutput = isBST2(root->right);
    int minm = min(root->data,min(leftOutput.minimum, rightOutput.minimum));
    int maxm = max(root->data,max(leftOutput.maximum, rightOutput.maximum));

    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

    BSTReturn output;
    output.isBST = isBSTFinal;
    output.maximum = maxm;
    output.minimum = minm;
    return output;


}


//Approach -3 : O(n)
bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if ( root == NULL)
    {
        return true;
    }
    if ( root->data >max || root->data< min)
    {
        return false;
    }
    bool isLeftOK = isBST3(root->left,min,root->data-1);
    bool isRightOK = isBST3(root->right,root->data,max);
    return isLeftOK && isRightOK;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    printBT_LW_newLine(root);
    // bool ans = isBST2(root).isBST;
    bool ans = isBST3(root);
    if (ans)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    
}