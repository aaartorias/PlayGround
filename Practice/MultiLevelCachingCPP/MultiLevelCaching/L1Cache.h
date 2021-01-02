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
    L1Cache(int capacity, int readTime, int writeTime, Cache* nextLevel = nullptr);

    string virtual readKey(string key);

    void virtual writeKey(string key, string value);

};

