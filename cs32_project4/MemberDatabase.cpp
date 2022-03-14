#include "MemberDatabase.h"

/*
 This method loads the member database from the data file specified by the filename parameter,
 e.g., members.txt. The method must load the data into data structures that enable efficient
 retrieval of email addresses (meeting the big-O requirements at the top of this section). The
 method must return true if the file was successfully loaded and false otherwise. If two members
 in the data file have the same email address, this method returns false.
 
 You may assume that there are no extraneous spaces at the beginning or ending of any line, or
 before or after any commas. The file may contain uppercase and lowercase letters. You may
 assume that there’s a single empty line separating each member in the file. You can look at our
 synthetically-generated members.txt file for an example of what you will have to parse
 */
bool MemberDatabase::LoadDatabase(string filename)
{
    //read in file - look at lecture for instructions
    
    //notes
    //key: emailaddresses
    //valuetype: pointer to a person profile
    
    //check if there is the same key
    //if there is, return false
    
    //if not the same key,
    //create a person profile for each member
    
    //create attribute string and create value string
    
    //create strings with format "attribute, value"
    
    //populate each member's person profiles' radixtree with their attributes
    
    //insert into the allMembers radixtree the key, mapped to pointer to the person profile
    
    //insert into allAttVals radixtree the attribute, value string mapped to set of strings representing the email addresses with that attribute
    
    //since we're using pointers, remember to create a destructor
    
    return true;
}

/*
 This method must identify all members that have the specified input attribute-value pair in an
 efficient manner (meeting the requirements at the top of this section) and return a vector
 containing their email addresses. If there are no such members, the vector returned must be
 empty. There is no particular order required for the email addresses in the vector returned. The
 vector returned must not contain duplicate email addresses.
 */
vector<string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const
{
    //create string of attribute,value out of given input
    string searcher = "";
    
    searcher += input.attribute;
    searcher += ",";
    searcher += input.value;
    
    return *(allAttVals.search(searcher));
}

const PersonProfile* MemberDatabase::GetMemberByEmail(string email) const
{
    return *(allMembers.search(email));
}
