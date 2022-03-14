#ifndef MatchMaker_h
#define MatchMaker_h

#include <iostream>
#include <string>
#include "provided.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"

using namespace std;

class AttributeTranslator;

class MatchMaker
{
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) {};
    ~MatchMaker() {};
    
    vector<EmailCount> IdentifyRankedMatches(std::string email, int threshold) const;
private:
    RadixTree<int> matches;
};

#endif /* MatchMaker_h */
