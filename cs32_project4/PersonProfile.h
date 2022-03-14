#ifndef PersonProfile_h
#define PersonProfile_h

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "provided.h"
#include "RadixTree.h"

using namespace std;

class PersonProfile
{
public:
    PersonProfile(string name, string email)
    {
        personName = name;
        personEmail = email;
    };
    ~PersonProfile() {};
    
    //accessors
    string GetName() const;
    string GetEmail() const;
    int GetNumAttValPairs() const;
    bool GetAttVal(int attribute_num, AttValPair& attval) const;
    
    //mutators
    void AddAttValPair(const AttValPair& attval);
private:
    string personName;
    string personEmail;
    RadixTree<set<string>> attValPairs;
    vector<AttValPair> allAtts;
};

#endif /* PersonProfile_h */
