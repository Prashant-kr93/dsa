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

TreeNode<int>* TakeInputLW(){
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

void PrintTree_LW(TreeNode<int>* root){
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

int numNodes(TreeNode<int> *root){
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1; // for root data
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int main(){
    TreeNode<int> *root = TakeInputLW();
    PrintTree_LW(root);
    cout<<numNodes(root)<<endl;
}