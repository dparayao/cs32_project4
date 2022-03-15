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
         //use recursion - make helper function to delete nodes
         deleteNodes(root);
         
        //delete root node
        delete root;
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
     void deleteNodes(RadixTreeNode* iterator);
};

template <typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType& value)
{
    RadixTreeNode* searcher = root;
    string keyCopy = key;
    
    int letter = key[0] - 'a';
     
    if((*searcher).edges[letter] == nullptr)
    {
        RadixTreeNode* newNode = new RadixTreeNode(key, value);
        (*newNode).parent = searcher;
        (*searcher).edges[letter] = newNode;
    }
    else
    {
        searcher = (*searcher).edges[letter];
         bool ifInTree = lookup(searcher, keyCopy);
         int prefixLength = int(keyCopy.length());
         
        //if returns true, the key is in the tree
        if(ifInTree == true)
        {
            (*searcher).value = value;
        }
        else if(keyCopy == (*searcher).word.substr(0,prefixLength))
        {
            //means key is not in tree but may also be a potential prefix
            string rest = (*searcher).word.substr(prefixLength);
            
            //must switch prefix's places with searcher
            letter = rest[0] - 'a';
             int holdLetter2 = keyCopy[0] - 'a';
            RadixTreeNode* newNode = new RadixTreeNode(keyCopy, value);
             (*searcher).parent->edges[holdLetter2] = newNode;
            (*newNode).parent = (*searcher).parent;
            (*newNode).endOfWord = false;
             (*newNode).edges[letter] = searcher;
             
             (*searcher).parent = newNode;
             (*searcher).word = rest;
             (*searcher).endOfWord = true;
        }
        else
        {
            //means key is not in tree + key does not have potential prefix - insert as usual
            letter = keyCopy[0] - 'a';
            RadixTreeNode* newNode = new RadixTreeNode(keyCopy, value);
            (*newNode).parent = searcher;
            (*searcher).endOfWord = false;
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
        return nullptr;
    }
    else
    {
        searcher = (*searcher).edges[letter];
         bool ifInTree = lookup(searcher, keyCopy);
        
        //if returns true, the key is in the tree
        if(ifInTree)
        {
            ValueType* hold = &((*searcher).value);
            return hold;
        }
        else
        {
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
    //note: since tree, trying to find node whose prefix matches the key's prefix
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
     
          if(prefix.length() < (*node).word.length())
          {
               //means it is a prefix
               node = current;
               return false;
          }
     
        if(endpoint == key.length())
        {
            //if reached end of one of the words and they are equal/same word
             key = prefix;
             node = current;
            return true;
        }
        
        //check edges
        //if the pointer at the int of the array is nullptr, return the current radixtreenode
        //if not, go to the radixtreenode that is held in the array
        letter = key[endpoint] - 'a';
        if((*current).edges[letter] == nullptr)
        {
            //means have same prefix, and there is an empty spot for the rest of the word
             key = key.substr(endpoint);
            return false;
        }
        else
        {
            key = key.substr(endpoint);
            current = (*current).edges[letter];
             bool res = lookup(current, key);
             node = current;
             return res;
        }
}


template <typename ValueType>
void RadixTree<ValueType>::deleteNodes(RadixTreeNode* iterator)
{
     if(iterator == nullptr)
     {
          return;
     }
     
     for(int i = 0; i < 128; i++)
     {
          deleteNodes((*iterator).edges[i]);
          
          RadixTreeNode* deletor = (*iterator).edges[i];
          delete deletor;
     }
}

#endif /* RadixTree_h */

