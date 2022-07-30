#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this ->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Queue{
    Node<T>* head;
    Node<T> *tail;
    int size;
    public:
    Queue(){
        head = tail = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }
    bool empty(){
        return size == 0;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop(){
        if (empty())
        {
            return ;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T front(){
        if (head == NULL)
        {
            return 0;
        }
        return head->data;   
    }

};


int main(){
    Queue<int> q;
    int t;
    cin>>t;
    while (t--)
    {
        int choice,input;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cin>>input;
                q.push(input);
                break;
            case 2:
                // cin>>choice;
                q.pop();
                break;
            case 3:
                // cin>>choice;
                cout<<q.front()<<endl;
                break;
            case 4:
                cout<<q.getSize()<<endl;
                break;
            default:
                cout<<(q.empty() ? "true" : "false")<<endl;
                break;
        }
    }
    
}