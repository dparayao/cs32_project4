#include "MatchMaker.h"


vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email, int threshold) const
{
    vector<EmailCount> identify;
    
    //have int indicating the least amt of count in the vector
    //have int indicating the most amt of count in the vector
    
    //given an email, retrieve the attribute values
    
    //create a set of compatible attribute values from the source attribute values
    
    //if radixtree matches doesn't have email address, populate radixtree matches with
    //key: email addresses
    //value: number of compatible attribute values - should be 1 initially
    //if 1 is greater than or equal to the threshold, add to the vector
    
    //if it does have email address
    //increment the number of compatible attribute values
    //if number is greater than or equal to the threshold, add to the vector
    //compare to least amt of count and most amt of count
    //if less than least add to end
    //if more than most add to front
    //if equal to either compare using email addresses
    //if within this domain iterate through front or back first depending on if closer to most or least
    
    //output the matches

    return identify;
}
