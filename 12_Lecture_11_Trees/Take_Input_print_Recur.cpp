#include<iostream>
using namespace std;
#include<vector>

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


TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data :";
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout<<"No. of children :";
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

// void printTree(TreeNode<int> *root){ // this fun print each node data in separate line which mess up

//     //edge case not base case
//     if (root == NULL)
//     {
//         return;
//     }
    
//     cout<<root->data<<endl;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children[i]);
//     }
    
// }


void printTree(TreeNode<int> *root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" : ";

    //printing the children of each node
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;

    //recursively call print fun for each further children
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    
    
}

int main(){
    TreeNode<int> *root = takeInput();
    printTree(root);
}