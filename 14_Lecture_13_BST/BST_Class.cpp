#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BST{
    //Define the data member
    BinaryTreeNode<int> *root;
    public:
    BST(){
        //implement the constructor
        root = NULL;
    }
    ~BST(){
        delete root;
    }

    /*------------------------Public Function -------------------*/
    private:
    BinaryTreeNode<int>* remove(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (node->data > data)
        {
            node->left = remove(node->left,data);
            return node;
        }
        else if ( node->data < data)
        {
            node->right = remove(node->right,data);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node -> left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node -> right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode = node->right;
                while (minNode-> left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node ->data = rightMin;
                node -> right = remove(node->right,rightMin);
                return node;
            }
            
        }
        
        
    }

    void printTree(BinaryTreeNode<int>* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL) {
			cout << "L:" << root->left->data<<",";
		}

		if (root->right != NULL) {
			cout << "R:" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);
	}

    public:
    void remove (int data){
        this->root = remove(this->root,data);
    }

    void print()
    {   
        printTree(this->root);
        // if (root == NULL)
        // {
        //     return;
        // }
        // queue<BinaryTreeNode<int>*> pn;
        // pn.push(root);
        // while (pn.size() != 0)
        // {
        //     BinaryTreeNode<int> *front = pn.front();
        //     pn.pop();
        //     cout<<front->data<<":";
        //     if (front->left)
        //     {
        //         cout<<"L:"<<front->left->data<<",";
        //         pn.push(front->left);
        //     }
        //     // else{
        //     //     cout<<endl;
        //     // }
        //     if (front->right)
        //     {
        //         cout<<"R:"<<front->right->data;
        //         pn.push(front->right);
        //     }
        //     // else{
        //     //     cout<<endl;
        //     // }
        //     cout<<endl;
        // }
    }

    private:
    BinaryTreeNode<int>* insertData(BinaryTreeNode<int> *node, int data){
        if (node == NULL)
        {
            BinaryTreeNode<int> *NewNode = new BinaryTreeNode<int>(data);
            return NewNode;
        }
        if ( node->data < data)
        {
            BinaryTreeNode<int>* rightNode =  insertData(node->right,data);
            node->right = rightNode;
        }
        else
        {
            BinaryTreeNode<int> *leftNode = insertData(node->left, data);
            node->left = leftNode;
        }
        return node;   
    }
    
    public:
    void insert(int data){
        this->root = insertData(this->root,data);
    }

    private:
    bool hasData(BinaryTreeNode<int> *node,int data){
        if ( node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if(node->data > data)
        {
            return hasData(node->left,data);
        }
        else{
            return hasData(node->right,data);
        }
        
    }
    public:
    bool search(int data){
        return hasData(root,data);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin>>q;
    while (q--)
    {
        cin>>choice;
        switch (choice)
        {
        case 1:
            cin>>input;
            tree->insert(input);
            break;
        
        case 2:
            cin>>input;
            tree->remove(input);
            break;

        case 3:
            cin>>input;
            cout<<((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
    
}