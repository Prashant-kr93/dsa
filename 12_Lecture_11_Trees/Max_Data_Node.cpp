#include<iostream>
#include<vector>
#include<climits>
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
            TreeNode<int>* child = new TreeNode<int>(childData);
            pn.push(child);
            front->children.push_back(child);
        }
        
    }
    return root;
}

void printTree_levelWise(TreeNode<int> *root){
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
            else
                cout<<front->children[i]->data<<",";
        }
        cout<<endl;
    }
    
    
}

TreeNode<int> *maxDataNode(TreeNode<int> *root){
    //Recursive approach
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *maxNode = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = maxDataNode(root->children[i]);
        if (maxNode->data < smallAns->data)
        {
            maxNode = smallAns;
        }
        
    }
    return maxNode;


    //iterative approach
    // TreeNode<int> *max = new TreeNode<int>(INT_MIN);
    // queue<TreeNode<int>*> pn;
    // pn.push(root);

    // while (pn.size() != 0)
    // {
    //     TreeNode<int>* front = pn.front();
    //     pn.pop();
    //     if (front->data > max->data)
    //     {
    //         max = front;
    //     }

    //     for (int i = 0; i < front->children.size(); i++)
    //     {
    //         pn.push(front->children[i]);
    //     }
    // }
    // return max;
}


int main(){
    TreeNode<int> *root = TakeInputLevelWise();
    TreeNode<int> *ans = maxDataNode(root);

    printTree_levelWise(root);
    if (root != NULL)
    {
        cout<<ans->data<<endl;
    }
    
}