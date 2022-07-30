#include <iostream>
using namespace std;

class Queue
{
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    Queue(int capacity)
    {
        data = new int[capacity];
        nextIndex = 0;
        firstIndex = -1; // not 0 because we are returning first index element of queue so if queue is empty
        this->size = 0;
        this->capacity = capacity;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int element)
    {
        if (size == capacity)
        {
            
            cout << "Queue is full !" << endl;
            return;

            // Dynamic queue
            int *newData = new int[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++) // copying of element from FI to last
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex;i++ )
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            
        }
        data[nextIndex] = element;
        // nextIndex++;  // wrong approach if our nextindex become equal to capacity then this way can't upadate nI. so nI= (nI+1)%capacity
        nextIndex = (nextIndex + 1) % capacity;

        // for the very first element in the queue have to check whether first element is or not;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;

        // if (nextIndex >= this->capacity)
        // {
        //     nextIndex = 0;
        //     if (firstIndex > nextIndex)
        //     {
        //         data[nextIndex] = element;
        //         nextIndex++;
        //         size++;
        //     }
        //     else
        //     {
        //         cout << "overflow!" << endl;
        //     }
        // }
        // else
        // {
        //     data[nextIndex] = element;
        //     nextIndex++;
        //     if (firstIndex == -1)
        //     {
        //         firstIndex = 0;
        //     }
        //     size++;
        // }
    }

    int front()
    {
        // check whether queue is empty
        if (size == 0)
        {
            cout << "Queue is Empty !" << endl;
        }

        return data[firstIndex];
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return 0;
        }

        int ans = data[firstIndex];
        // firstIndex++; //wrong approach for update firstindex reason same as nextindex
        firstIndex = (firstIndex + 1) % capacity;
        size--;

        // now if our queue become fully empty and we may reset our firstindex and nI so that next time if we get choice for
        // add new element then we can easily do that so totally depend on Q, there is not necessary for reset fi and ni;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans; // finally return front element(ans)

        //         if (firstIndex < 0)
        //         {
        //             return -1;
        //         }
        //         int ans = data[firstIndex];
        //         if (firstIndex >= this->capacity)
        //         {
        //             if (nextIndex >= 0)
        //             {
        //                 firstIndex = 0;
        //             }
        //             size--;
        //             return ans;
        //         }
        //         else
        //         {
        //             firstIndex++;
        //             size--;
        //             return ans;
        //         }
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getsize() << endl;
    cout << q.front() << endl;

    cout << q.dequeue() << endl;
    cout << q.getsize() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}