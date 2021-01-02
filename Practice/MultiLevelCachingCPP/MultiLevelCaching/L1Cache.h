#pragma once
#include "Cache.h"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

class L1Cache: public Cache
{

public:

    L1Cache(int capacity, int readTime, int writeTime, Cache* nextLevel = nullptr);

    // TODO: for L2Cache and L3 cache implement other eviction policy
    // for L1Cache(current class), use LRU
    // Do this by making function below purely virtual

    //void virtual insertInCache(string key, string value);

    //string virtual readKey(string key);

    //void virtual writeKey(string key, string value);

};

