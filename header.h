#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>
#include <map>
using namespace std;

struct Room {
    string description;
    map<string, int> exits;
    vector<string> items; // #16 DynamicArrays_Vectors - Vector. slide 13
    map<string, bool> locked;
    map<string, string> features;
};

class Player { // #17 Classes - slide 5
public: // #18 Multiple Inheritance - slide 5
    vector<string> inventory;
};

#endif
