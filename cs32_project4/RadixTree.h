#ifndef RadixTree_h
#define RadixTree_h

//cur dummy implementation uses unordered map
//TO DO: change later
#include <unordered_map>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

struct RadixTreeNode;

template <typename ValueType>
class RadixTree {
public:
    RadixTree()
    {
        root = new RadixTreeNode();
    };
    ~RadixTree()
    {
        //delete root node
        delete root;
        
        //use recursion - make helper function to delete nodes
    };
    void insert(string key, const ValueType& value);
    ValueType* search(string key) const;
private:
    struct RadixTreeNode
    {
        RadixTreeNode()
        {
            word = "";
        }
        
        RadixTreeNode(string n_word, ValueType n_value)
        {
        
            word = n_word;
            endOfWord = true;
            value = n_value;
        };
        
        string word;
        bool endOfWord;
        ValueType value;
        
        RadixTreeNode* parent = nullptr;
        RadixTreeNode* edges[128] = {};
    };
    
    unordered_map <string, ValueType> fakeTree;
    int numPairs = 0;
    RadixTreeNode* root = nullptr;
    
    //helper functions
    bool lookup(RadixTreeNode*& node, string& key) const;
};

template <typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType& value)
{
    RadixTreeNode* searcher = root;
    string keyCopy = key;
    
    int letter = key[0] - 'a';
    
    if((*searcher).edges[letter] == nullptr)
    {
        cout << "inserting" << endl;
        RadixTreeNode* newNode = new RadixTreeNode(key, value);
        (*searcher).edges[letter] = newNode;
    }
    else
    {
        searcher = (*searcher).edges[letter];
        
        //if returns true, the key is in the tree
        if(lookup(searcher, keyCopy))
        {
            cout << "not inserting" << endl;
            (*searcher).value = value;
        }
        else
        {
            cout << "inserting" << endl;
            //if it returns false, the whole key is not in the tree
            letter = keyCopy[0] - 'a';
            RadixTreeNode* newNode = new RadixTreeNode(keyCopy, value);
            (*searcher).edges[letter] = newNode;
        }
    }
}

/*
 The search method is responsible for searching your Radix Tree for the specified key. If the key is found, then the search method must return a pointer to the value associated with the key. If the specified key was not found, the method must return nullptr. If this method returns a non-null pointer, the caller is free to modify the value held within the Radix Tree
 */
template <typename ValueType>
ValueType* RadixTree<ValueType>::search(string key) const
{
    RadixTreeNode* searcher = root;
    string keyCopy = key;
    
    int letter = key[0] - 'a';
    
    if((*searcher).edges[letter] == nullptr)
    {
        cout << "not found" << endl;
        return nullptr;
    }
    else
    {
        searcher = (*searcher).edges[letter];
        
        //if returns true, the key is in the tree
        if(lookup(searcher, keyCopy))
        {
            cout << "found" << endl;
            ValueType* hold = &((*searcher).value);
            return hold;
        }
        else
        {
            cout << "not found" << endl;
            //if returns false, the key is not in the tree
            return nullptr;
        }
    }
}

//returns if it reached the end of the key or not
//if true, means there is the key in the tree
//if false, means there is no key in the tree
//node either holds the node with the key, or a prefix of the word
template <typename ValueType>
bool RadixTree<ValueType>::lookup(RadixTreeNode*& node, string& key) const
{
    //note: since trie, trying to find node whose prefix matches the key's prefix
    RadixTreeNode* current = node;
    int letter = key[0] - 'a';
    string prefix = "";
    string curWord = "";
    int endpoint = 0;
    
    while(endpoint < key.length() || endpoint < (*current).word.length())
    {
        if(key[endpoint] != (*current).word[endpoint])
        {
            //reached end of matching prefix
            break;
        }
        else
        {
            prefix += key[endpoint];
            curWord += (*current).word[endpoint];
            endpoint++;
        }
    }
    
    if((endpoint == key.length() || endpoint == (*current).word.length()) && prefix == curWord)
    {
        //if reached end of one of the words and they are equal/same word
        cout << prefix << " this way" << endl;
        return true;
    }
    else if(prefix == curWord)
    {
        //check edges
        //if the pointer at the int of the array is nullptr, return the current radixtreenode
        //if not, go to the radixtreenode that is held in the array
        letter = key[endpoint] - 'a';
        if((*current).edges[letter] == nullptr)
        {
            //means have same prefix, and there is an empty spot for the rest of the word
            return false;
        }
        else
        {
            key = key.substr(endpoint);
            current = (*current).edges[letter];
            return lookup(current, key);
        }
    }
    else
    {
        //reached the end of one of the words and they are not same word
        return false;
    }
}

#endif /* RadixTree_h */
