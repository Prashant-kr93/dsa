#include<iostream>
#include<queue>
#include<climits>
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
};

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        int leftData, rightData;
        cin>>leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftData);
            pn.push(leftNode);
            front->left = leftNode;
        }
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

pair<int,int> getMinAndMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int,int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    pair<int,int> leftAns = getMinAndMax(root->left);
    pair<int,int> rightAns = getMinAndMax(root->right);

    int minm = min(leftAns.first,min(rightAns.first, root->data));
    int maxm = max(leftAns.second,max(rightAns.second, root->data));
    pair<int, int> ans;
    ans.first = minm;
    ans.second = maxm;
    return ans;

}
int main(){
    BinaryTreeNode<int> *root = takeInput();
    pair<int,int> ans = getMinAndMax(root);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}