#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    int getMax()
    {
        return pq[0];
    }
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMax()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // Heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq.size() )
        {
            int maxIndex = parentIndex;

            if (pq[maxIndex] < pq[leftChildIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < pq.size() &&  pq[maxIndex] < pq[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex)
            {
                break;
            }
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue pq;
    int choice;
    cin>>choice;
    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            int element;
            cin>>element;
            pq.insert(element);
            break;
        case 2:
            cout<<pq.getMax()<<endl;
            break;
        case 3:
            cout<<pq.removeMax()<<endl;
            break;
        case 4:
            cout<<pq.getSize()<<endl;
            break;
        case 5:
            cout<<(pq.isEmpty() ? "true\n":"false\n");
        default:
            return 0;
        }
        cin>>choice;
    }
    
}