#include <iostream>
#include <string>
#include "provided.h"
#include "RadixTree.h"

using namespace std;

void testPersonProfile()
{
    
}

void testRadixTree()
{
    RadixTree<int>* test = new RadixTree<int>;
    (*test).insert("help",400);
    (*test).insert("apple",3);
    (*test).insert("helper",500);
    (*test).insert("helping",570);
    int* testint = (*test).search("helping");
    cout << *testint << endl;
}
