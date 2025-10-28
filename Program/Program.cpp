#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        int key;
        int value;
        
        Node * next;
    };

    struct Bucket
    {
        int size;
        int capacity;

        Bucket * bucket = new Bucket[8];
        Bucket * head;
    };

public:
    HashTable()
    {
        
    }
};

int main()
{
    HashTable<int, int> hashtable;

    return 0;
}