#ifndef RadixTree_h
#define RadixTree_h

//cur dummy implementation uses unordered map
//TO DO: change later
#include <unordered_map>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

template <typename ValueType>
class RadixTree {
public:
    RadixTree() {};
    ~RadixTree() {};
    void insert(string key, const ValueType& value);
    ValueType* search(string key) const;
private:
    unordered_map <string, ValueType> fakeTree;
    int numPairs = 0;
    //real has function to help search in general - that will return key to be used by insert and search
    
};

template <typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType& value)
{
    fakeTree[key] = value;
}

/*
 The search method is responsible for searching your Radix Tree for the specified key. If the key is found, then the search method must return a pointer to the value associated with the key. If the specified key was not found, the method must return nullptr. If this method returns a non-null pointer, the caller is free to modify the value held within the Radix Tree
 */
template <typename ValueType>
ValueType* RadixTree<ValueType>::search(string key) const
{
    typename unordered_map<string, ValueType>::const_iterator iter;
    
    iter = fakeTree.find(key);
    
    if(iter == fakeTree.end())
    {
        return nullptr;
    }
    else
    {
        return const_cast<ValueType*>(&(iter->second));
    }
    
}

#endif /* RadixTree_h */
