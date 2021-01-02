#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

// Cache - LRU eviction policy
// Other classes extending Cache class can either use the same 
// eviction algorithm or they can implement their own cache eviction algorithm
// If eviction policies across all Caches were same, we would create sa

class Cache {

protected:

    unordered_map<string, list<pair<string, string>>::iterator > map;
    list<pair<string, string>> lst;
    int capacity;
    int readTime;
    int writeTime;
    Cache* nextLevel;

public:


    Cache(int capacity=0, int readTime=0, int writeTime = 0, Cache* nextLevel = nullptr);

    void virtual insertInCache(string key, string value);

    list<pair<string, string>>::iterator insertInList(string key, string value);

    void  insertInMap(string key, list<pair<string, string>>::iterator value);

    void removeFromList(list<pair<string, string>>::iterator nodeToRemove);

    void removeKeyFromMap(string key);

    void updateRecentlyAccessed(list<pair<string, string>>::iterator node);

    string virtual readKey(string key, int& time);

    void virtual writeKey(string key, string value, int& time);

    void printCacheContents();

    void printCacheUsage();

    float getCurrentUsage();

};
