#include "AttributeTranslator.h"

/*
 
 This method loads the attribute-value translation data from the data file specified by the filename parameter. The method must return true if the file was successfully loaded and false otherwise.
 You must ignore all empty lines. You may assume that there are no extraneous spaces before or after any comma or at the beginning or end of any line, and that neither attributes nor values will have any commas in them. You may assume that the file is all lower-case and you do not need to do case-insensitive checks.
 */
bool AttributeTranslator::Load(string filename)
{
    //notes:
    //source attribute and source value are the key
    //set of "compatible attribute,compatible value" strings (in that format) are the value type
    
    //load in file
    //note: check lecture for steps
    
    //create string for the source attribute,source value
    //create string for compatible attribute,compatible value
    
    //search if the source attribute,source value is in the tree
    
    //if not, create set for compatible attributes/values
    //insert into tree
    
    //if it is there
    //retrieve the compatible attributes/values set using search
    //add the compatible attribute/value to the set
    
    return true;
}

/*
 This method must identify all compatible attribute-value pairs for the specified source attribute- value pair in an efficient manner (meeting the requirements at the top of this section) and return a vector containing them. If there are no compatible pairs, the vector returned must be empty. There is no particular order required for the AttValPairs in the vector returned. The vector returned must not contain two attribute-value pairs with the same attributes and values (i.e., no duplicates).
 */
vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const
{
    vector<AttValPair> foundPairs;
    
    //create a string for the source attribute,source value
    
    //search the radixtree for the key
    
    //if the key isn't found, return an empty vector (foundPairs)
    
    //otherwise, if the key is found, create attvalpairs for each element in the set
    //insert the attvalpairs into vector foundPairs
    
    return foundPairs;
}
