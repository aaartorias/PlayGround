#pragma once
#include "Cache.h"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

class L2Cache : public Cache
{

public:

    L2Cache(int capacity, int readTime, int writeTime, Cache* nextLevel = nullptr);
    
    // TODO: Levearge these functions to create new eviction policy

    //void virtual insertInCache(string key, string value);

    //string virtual readKey(string key);

    //void virtual writeKey(string key, string value);
};

