#include <iostream>
using namespace std;

class Stack
{
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    Stack(int capacity)
    {
        data = new int[capacity];
        size = 0;
        nextIndex = 0;
        firstIndex = -1;
        this->capacity = capacity;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void push(int element){
        data[nextIndex] = element;
        if (firstIndex == -1)
        {
            firstIndex = nextIndex;
        }
        nextIndex++;
        size++;
    }
    int pop(){
        if(firstIndex >= capacity){
            return -1;
        }
        int ans = data[firstIndex];
        firstIndex++;
        size--;
        return ans;
    }
    int top(){
        if (firstIndex >= capacity)
        {
            return -1;
        }
        return data[firstIndex];
    }
};

int main()
{
    Stack st(5);
    int t;
    cin >> t;
    while (t--)
    {
        int choice, input;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cin>>input;
            st.push(input);
            break;
        case 2:
            cout<<st.top()<<endl;
            break;
        case 3:
            cout<<st.pop()<<endl;
            break;
        case 4:
            cout<<st.getSize()<<endl;
            break;
        default:
            bool ans = st.isEmpty() ? "true":"false";
            cout<<ans<<endl;
            break;
        }
    }
}