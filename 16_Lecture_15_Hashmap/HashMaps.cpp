#include <iostream>
#include <string>
using namespace std;

template <typename v>
class MapNode
{
public:
    string key;
    v value;
    MapNode<v> *next;

public:
    MapNode(string key, v value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename v>
class ourmap
{
    MapNode<v> **buckets; // array of pointer of MapNode
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<v> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int baseP = 37;       // any prime num we want for just good differentiation
        int currentCoeff = 1; // here we start from last char of string so power of baseP to the 0 is 1
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;

            currentCoeff = currentCoeff * baseP;
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets;
    }

public:
    void insert(string key, v value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<v> *newNode = new MapNode<v>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++; // important step is that after adding new entries size must be increased
    }
    v getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);// find the index
        MapNode<v>* head = buckets[bucketIndex];// head of LL
        while (head != NULL)
        {
            if (head->key == key)//if found, return the value
            {
                return head->value;
            }
            
            head = head->next;
        }
        return 0;//if not found, returning 0 as default value.
    }

    //to delete the key-value pair
    v remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        MapNode<v> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                v ans = head->value;
                head->next = NULL;
                delete head;
                count--; // important step
                return ans;
            }
            prev = head;
            head = head->next;
        }
        return 0; // signifying not found;
    }
};

int main()
{
    ourmap<int> mp;
    mp.insert("a", 1);
    mp.insert("b", 2);
    mp.insert("c", 3);
    mp.insert("d", 4);
    cout << mp.size() << endl;
    mp.remove("c");
    cout << mp.size() << endl;
    cout<<mp.getValue("d")<<endl;
    mp.insert("c",5);
    cout << mp.size() << endl;
}