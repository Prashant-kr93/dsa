#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // Heapify
        int pi = 0; // ParentIndex
        int LeftChildIndex = 2 * pi + 1;
        int rightChildIndex = 2 * pi + 2;
        int minIndex;

        while (LeftChildIndex < pq.size() && rightChildIndex < pq.size())
        {
            if (pq[LeftChildIndex] < pq[rightChildIndex])
            {
                minIndex = LeftChildIndex;
                int temp = pq[minIndex];
                pq[minIndex] = pq[pi];
                pq[pi] = temp;
            }
            else if (pq[LeftChildIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
                int temp = pq[minIndex];
                pq[minIndex] = pq[pi];
                pq[pi] = temp;
            }
            else
            {
                break;
            }
            pi = minIndex;
            LeftChildIndex = 2*pi + 1;
            rightChildIndex = 2*pi + 2;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            int element;
            cin >> element;
            pq.insert(element);
            break;

        case 2:
            cout << pq.getMin()<<endl;
            break;

        case 3:
            cout << pq.removeMin()<<endl;
            break;

        case 4:
            cout << pq.getSize()<<endl;
            break;

        case 5:
            cout << (pq.isEmpty() ? "true" : "false") << endl;

        default:
            return 0;
        }
        cin >> choice;
    }
}