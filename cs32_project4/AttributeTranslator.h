#ifndef AttributeTranslator_h
#define AttributeTranslator_h

#include <iostream>
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
};

#endif /* AttributeTranslator_h */
