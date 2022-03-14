#ifndef MemberDatabase_h
#define MemberDatabase_h

#include <iostream>
#include <string>
#include <vector>
#include "PersonProfile.h"
#include "provided.h"

using namespace std;

class PersonProfile;

class MemberDatabase
{
public:
    MemberDatabase() {};
    ~MemberDatabase() {};
    
    bool LoadDatabase(string filename);
    
    vector<string> FindMatchingMembers(const AttValPair& input) const;
    
    const PersonProfile* GetMemberByEmail(string email) const;
private:
    RadixTree<PersonProfile*> allMembers;
    RadixTree<vector<string>> allAttVals;
};

#endif /* MemberDatabase_h */
