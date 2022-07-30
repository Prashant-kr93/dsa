/*
For a given a string expression containing only round brackets or parentheses, 
check if they are balanced or not. Brackets are said to be balanced if 
the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, 
we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.
Input Format:
The first and the only line of input contains a string 
expression without any spaces in between.
 Output Format:
The only line of output prints 'true' or 'false'.
Note:
You don't have to print anything explicitly. It has been taken 
care of. Just implement the function. 
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, 
the opening bracket at the fourth index doesn't have its corresponding 
closing bracket which makes it imbalanced and in turn, making the whole 
expression imbalanced. Hence the output prints 'false'.

*/



#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Stack{
    Node<T> *head;
    int Size;
    public:
    Stack(){
       head = NULL;
       Size = 0; 
    }
    int size(){
        return Size;
    }
    bool empty(){
        return Size == 0;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        Size++;
    }

    T top(){
        if (head == NULL) return 0;
        return head->data;
    }

    void pop(){
        if (empty())
        {
            return;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        Size--;
    }
};

bool isBalanced(string expression){
    Stack<char> st;
    char open[3] = {'{','[','('};
    char close[3] = {'}',']',')'};
    for (int i = 0; i < expression.length(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (expression[i] == open[j])
            {
                st.push(expression[i]);
            }
            else if (expression[i] == close[j])
            {
                if (st.top() == open[j])
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            
        }
           
    }
    return st.empty();
    // if (st.empty())
    // {
    //     return true;
    // }
    // else return false;

}

int main(){
    string input;
    cin>>input;
    cout << ((isBalanced(input)) ? "true" : "false")<<endl;



    // Stack<int> st;
    // int q;
    // cin>>q;

    // while (q--) {
    //     int choice, input;
    //     cin >> choice;
    //     switch (choice) {
    //         case 1:
    //             cin >> input;
    //             st.push(input);
    //             break;
    //         case 2:
    //             // cout << st.pop() << "\n";
    //             st.pop();
    //             break;
    //         case 3:
    //             cout << st.top() << "\n";
    //             break;
    //         case 4:
    //             cout << st.size() << "\n";
    //             break;
    //         default:
    //             cout << ((st.empty()) ? "true\n" : "false\n");
    //             break;
    //     }
    // }
}