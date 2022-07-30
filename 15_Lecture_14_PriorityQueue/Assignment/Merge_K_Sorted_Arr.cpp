#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class triplet{
    public:
    int element;
    int arrIndex;
    int elementIndex;
};

vector<int> mergeKSotedArrays(vector<vector<int>*> input){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i]->size(); j++)
        {
            minHeap.push(input[i]->at(j));
        }
        
    }
    vector<int> output;
    while (! minHeap.empty())
    {
        output.push_back(minHeap.top());
        minHeap.pop();
    }
    return output;
}

int main()
{
    int k;
    cin>>k;
    vector<vector<int>*> input;
    while (k--)
    {
        int n;
        cin>>n;
        vector<int> *current = new vector<int>;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin>>ele;
            current->push_back(ele);
        }
        input.push_back(current);
    }

    //print 2D vector
    // for (int i = 0; i < input.size(); i++)
    // {
    //     for (int j = 0; j < input[i]->size(); j++){
    //         cout<<input[i]->at(j)<<" ";
    //     }
    //     cout<<endl;
    // }
    

    vector<int> output = mergeKSotedArrays(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;

}