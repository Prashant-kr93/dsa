/*
Given a generic tree, count and return the number of leaf nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
Output Format :
The first and only line of output prints the count of leaf nodes present in the given tree.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4
*/

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

void printTreeLevelWise(TreeNode<int> *root){
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
        for (int i = 0; i < front->children.size() ; i++)
        {
            pn.push(front->children[i]);
            if (i == front->children.size())
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

int getLeafNodeCount(TreeNode<int> *root){
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
}


int main(){
    TreeNode<int> *root = TakeInputLevelWise();
    printTreeLevelWise(root);
    cout<<getLeafNodeCount(root)<<endl;
    return 0;
}