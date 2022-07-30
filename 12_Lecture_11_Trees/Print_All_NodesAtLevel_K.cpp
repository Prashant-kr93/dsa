#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;

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

void PrintTreeNodeLevelWise(TreeNode<int> *root){
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int>*> pn;
    pn.push(root);
    while (pn.size() != 0)
    {
        TreeNode<int> *front = pn.front();
        pn.pop();
        cout<<front->data<<":";
        for (int i = 0; i < front->children.size(); i++)
        {
            pn.push(front->children[i]);
            if (i == front->children.size() - 1)
            {
                cout<<front->children[i]->data;
            }
            else{
                cout<<front->children[i]->data<<",";
            }
        }
        cout<<endl;
    }
    
}

void PrintAllNodes_LevelK(TreeNode<int>* root, int k){
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout<<root->data<<" ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintAllNodes_LevelK(root->children[i], k-1);
    }
    
}


int main(){
    TreeNode<int> *root = TakeInputLevelWise();
    PrintTreeNodeLevelWise(root);
    int k;
    cin>>k;
    PrintAllNodes_LevelK(root,k);
}