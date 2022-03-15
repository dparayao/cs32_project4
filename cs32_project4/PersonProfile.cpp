#include "PersonProfile.h"

string PersonProfile::GetName() const
{
    return personName;
}

string PersonProfile::GetEmail() const
{
    return personEmail;
}

int PersonProfile::GetNumAttValPairs() const
{
    return int(allAtts.size());
}

/*This method gets the attribute-value pair specified by attribute_num (where 0 <= attribute_num < GetNumAttValPairs()) and places it in the attval parameter. The method returns true if it successfully retrieves an attribute; otherwise, it returns false and leaves attval unchanged.*/
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const
{
    //if the attribute vector is empty, return false
    if(allAtts.empty())
    {
        return false;
    }
    
    //otherwise
    //retrieves a pointer from vector to a desired attribute based on the number given
    //search time - O(1)
    attval = allAtts[attribute_num];
    
    return true;
}

/*The AddAttValPair method is used to add a new attribute-value pair to the member’s profile. If the person’s profile already has an attribute-value pair with the same attribute and value as the attval parameter, then this method should do nothing. More than one attribute-value pair in the map can have the same attribute, as long as their corresponding values are different. We place no requirements on the order that you must store your attribute-value pairs.*/
void PersonProfile::AddAttValPair(const AttValPair& attval)
{
    cerr << "adding" << endl;
    bool ifAdded = false;
    
    //see if the key is already in the radix tree
    set<string>* values = attValPairs.search(attval.attribute);
    if(values == nullptr)
    {
        cerr << "making new " << endl;
        //if it's not, create a new string set to hold the values
        set<string> newValues;
        newValues.insert(attval.value);
        
        //insert the key and map the string of values to the key (attribute)
        attValPairs.insert(attval.attribute, newValues);
        ifAdded = true;
    }
    else
    {
        //add the value to the already existing set of values mapped to the key
        //since it's a set, will only insert if it's unique
        //unused code: (*values).insert(attval.value);
        if( !(*values).insert(attval.value).second )
        {
            //if it didn't add bc duplicate, set ifAdded to false
            ifAdded = false;
        }
        else
        {
            ifAdded = true;
        }
    }
    
    if(ifAdded)
    {
        //if it added it, add to the vector of attvalue apirs
        cerr << "push" << endl;
        allAtts.push_back(attval);
    }
}
