#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<int>*> children;

        TreeNode(T data){
            this->data = data;
        }
        ~TreeNode(){
            for (int i = 0; i < children.size(); i++)
            {
                delete children[i];
            }
            
        }
};

TreeNode<int> *TakeInputLevelWise(){
    int rootData;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pn;
    pn.push(root);

    while (pn.size() != 0)
    {
        TreeNode<int> *front = pn.front();
        pn.pop();
        int numChild;
        cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);

            pn.push(child);
            front->children.push_back(child);
        }
        
    }
    return root;
}


void PreOrder(TreeNode<int> *root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    for (int i = 0; i < root->children.size(); i++)
    {
        PreOrder(root->children[i]);
    }
    
}

int main(){
    TreeNode<int> *root = TakeInputLevelWise();
    PreOrder(root);
    return 0;
}