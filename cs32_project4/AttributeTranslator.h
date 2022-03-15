#ifndef AttributeTranslator_h
#define AttributeTranslator_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "RadixTree.h"
#include "provided.h"

using namespace std;

class AttributeTranslator
{
public:
    AttributeTranslator() {};
    ~AttributeTranslator() {};
    
    bool Load(string filename);
    
    vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
private:
    RadixTree<set<string>> compPairs;
    
    //helper functions
    string createStrings(string& line);
    void printPairs(string key);
};

#endif /* AttributeTranslator_h */
