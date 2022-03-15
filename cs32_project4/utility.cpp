#include <iostream>
#include <string>
#include "provided.h"
#include "RadixTree.h"
#include "PersonProfile.h"
#include "AttributeTranslator.h"

using namespace std;

void testPersonProfile()
{
    PersonProfile pp("Carey Nachenberg", "climberkip@gmail.com");
    AttValPair av("hobby", "rock climbing");
    AttValPair ff("favorite food", "del taco");
    AttValPair ff2("favorite food", "taco bell");
    AttValPair ff3("favorite food", "del taco");
    pp.AddAttValPair(av);
    pp.AddAttValPair(ff);
    pp.AddAttValPair(ff2);
    pp.AddAttValPair(ff3);
    cout << "size: " << pp.GetNumAttValPairs() << endl;
    for(int i = 0; i != pp.GetNumAttValPairs(); i++)
    {
        AttValPair hold;
        pp.GetAttVal(i, hold);
        cout << hold.attribute << " -> " << hold.value << endl;
    }
}

void testAttributeTranslator()
{
    AttributeTranslator tester;
    tester.Load("/Users/dagnyparayao/Downloads/Unhinged/translator.txt");
    AttValPair att("favorite food", "del taco");
    vector<AttValPair> result = tester.FindCompatibleAttValPairs(att);
    if(!result.empty())
    {
        cout << "comp: " << endl;
        for(const auto&p: result)
        {
            cout << p.attribute << " -> " << p.value << endl;
        }
    }
    //tester.printPairs("trait, transparent");
}

void testRadixTree()
{
    RadixTree<int>* test = new RadixTree<int>;
    (*test).insert("help",400);
    (*test).insert("apple",3);
    (*test).insert("helping",570);
    (*test).insert("helpers",5010);
    (*test).insert("helper",500);
    cout << "Lookiing" << endl;
    int* testint = (*test).search("helper");
    int* testint2 = (*test).search("helpers");
    cout << *testint << endl;
    cout << *testint2 << endl;
    int* testint3 = (*test).search("apple");
    cout << *testint3 << endl;
    (*test).insert("apple",34);
    int* testint4 = (*test).search("apple");
    cout << *testint4 << endl;
}
