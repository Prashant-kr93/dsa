#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename v>
class MapNode
{
public:
    string key;
    v value;
    MapNode<v> *next;
    MapNode(string key, v value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next; // recursively delete all next next node of linked list.
    }
};

template <typename v>
class ourmap
{
    MapNode<v> **buckets;
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
    int getBucketIndex(string key)// to provide index using hash function
    {
        int hashCode = 0;
        int baseP = 37;
        int currentCoeff = 1;
        //using "abcd" = ('a'*p^3) + ('b'*p^2) + ('c'*p^1) + ('d'*p^0(=1)) as our hash code
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;

            currentCoeff *= baseP;
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets;
    }

    void rehash(){
        MapNode<v>** temp = buckets;// store old buckets in temp
        buckets = new MapNode<v>*[2*numBuckets];//doubling the size
        for (int i = 0; i < 2*numBuckets; i++)
        {
            buckets[i] = NULL;// initialize each head pointer to NULL
        }
        int oldNumBuckets = numBuckets;
        numBuckets *= 2; // now num of bucket will be 2 times of initial
        count = 0; // count must be 0 for new buckets of double size because now new bucket is empty.
        for (int i = 0; i < oldNumBuckets; i++)
        {
            MapNode<v>* head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                v value = head->value;
                insert(key,value);
                head = head->next;
            }
            
        }

        //Now delete the old buckets and LL of every index of buckets
        for (int i = 0; i < oldNumBuckets; i++)
        {
            delete temp[i];
        }
        delete[] temp;
        
    }

public:
    double getLoadFactor(){
        return (1.0)*count/numBuckets;
    }
    void insert(string key, v value)
    {
        int bucketIndex = getBucketIndex(key);   // find the index
        MapNode<v> *head = buckets[bucketIndex]; // head of linked list
        while (head != NULL)
        {
            if (head->key == key) // if key already present then
            {                     // just updating the value
                head->value = value;
                return;
            }
            head = head->next;
        }
        // otherwise make new node and insert that node
        // before head so making it as the head and marking
        //  the bucket index to this node as the new head
        head = buckets[bucketIndex];
        MapNode<v> *newNode = new MapNode<v>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++; // important step to increase the size of map.

        //rehashing must be after inserting
        //Now we will check the Load factor after insertion
        double loadFactor = (1.0)*count/numBuckets;// loadFactor = n/b, where n = num of entries  & b= num 0f buckets
        if (loadFactor > 0.7)
        {
            rehash(); // we will rehash the map
        }
        
    }

    //search for the key
    v getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);//find the index
        MapNode<v>* head = buckets[bucketIndex];// head of the LL
        while (head != NULL)
        {
            if (head->key == key)// if found return the value
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;// if not found, returning 0 as default value
    }


// to delete the key-value pair
    v remove(string key)
    {
        int bucketIndex = getBucketIndex(key);//find the index for given key
        MapNode<v>* head = buckets[bucketIndex];// head node of linked list
        MapNode<v>* prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)// if found, return the value
            {
                if (prev == NULL) // if key is found at head
                {
                    buckets[bucketIndex] = head->next;
                }
                else{// otherwise connecting previous pointer to next head pointer
                    prev->next = head->next;
                }
                //DELETE NODE
                v value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            
            prev = head;
            head = head-> next;
        }
        return 0;
    }
};

int main()
{
   ourmap<int> map;
   for (int i = 0; i < 10; i++)
   {
       char c = '0'+i;
       string key = "abc";
       key += c;
       int value = i + 1;
       map.insert(key,value);
       cout<<map.getLoadFactor()<<endl;
   }

   cout<<map.size()<<endl;
   map.remove("abc2");
   map.remove("abc7");
   cout<<map.size()<<endl;
   for (int i = 0; i < 10; i++)
   {
       char c = '0'+i;
       string key = "abc";
       key+= c;
       cout<<key<<":"<<map.getValue(key)<<endl;
   }
   cout<<map.size()<<endl;

}