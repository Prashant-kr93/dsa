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
            this ->data = data;
        }

        ~TreeNode(){
            for (int i = 0; i < children.size(); i++)
            {
                delete children[i];
            }
            
        }
};

TreeNode<int> * TakeInputLevelWise(){
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

void PrintTreeLevelWise(TreeNode<int> *root){
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
            if (i == front->children.size() -1)
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

int getHeight(TreeNode<int>* root){
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallans = getHeight(root->children[i]);
        if (ans<smallans)
        {
            ans = smallans;
        }
        
    }
    return ans+1;

    //M-II
    // int h =1;
    
    // if(root->children.size()==0)
    //     return h;	
    
    // int arr[root->children.size()];
    // for(int i=0;i<root->children.size();i++)
    // {
    //     arr[i]=getHeight(root->children[i]);
        
    // }
    // sort(arr,arr+root->children.size(),greater<int>());
	// h+=arr[0];
    
    // return h;
    
}

int main(){
    TreeNode<int> *root = TakeInputLevelWise();
    PrintTreeLevelWise(root);
    cout<<getHeight(root)<<endl;
    return 0;
}