#include "Cache.h"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;


Cache::Cache(int capacity, int readTime, int writeTime, Cache* nextLevel) {

    this->capacity = capacity;
    this->readTime = readTime;
    this->writeTime = writeTime;
    this->nextLevel = nextLevel;
}

void Cache::insertInCache(string key, string value) {

    list<pair<string, string>>::iterator lastNode;
    list<pair<string, string>>::iterator firstNode;
    if (capacity > 0) {
        if (lst.size() == capacity)
        {
            lastNode = lst.end();
            --lastNode;
            removeKeyFromMap(lastNode->first);
            removeFromList(lastNode);
        }
        firstNode = insertInList(key, value);
        insertInMap(key, firstNode);
    }

}

list<pair<string, string>>::iterator  Cache::insertInList(string key, string value) {
    pair<string, string> node = make_pair(key, value);
    lst.push_front(node);
    return lst.begin();
}

void Cache::insertInMap(string key, list<pair<string, string>>::iterator value) {
    pair<string, list<pair<string, string>>::iterator> keyValuePair = make_pair(key, value);
    map.insert(keyValuePair);
}

void Cache::removeFromList(list<pair<string, string>>::iterator nodeToRemove) {
    lst.erase(nodeToRemove);
}

void Cache::removeKeyFromMap(string key) {
    if (map.find(key) != map.end()) {
        map.erase(key);
    }
}

void Cache::updateRecentlyAccessed(list<pair<string, string>>::iterator node) {
    // move the "node" to front of the list
    // position = lst.begin(), list = lst, index_to_move = node
    lst.splice(lst.begin(), lst, node);
}

string Cache::readKey(string key, int& time) {
    time += this->readTime;
    if (map.find(key) == map.end()) {

        string value;
        if (nextLevel) {
            value = nextLevel->readKey(key, time);
        }
        else {
            return "";
        }
        if (value == "") {
            return "";
        }
        else {
            time += this->writeTime;
            insertInCache(key, value);
            return value;
        }
    }
    else {
        updateRecentlyAccessed(map[key]);
        return map[key]->second;
    }
}

void Cache::writeKey(string key, string value, int& time) {
    time += this->readTime;
    if (map.find(key) == map.end()) {
        insertInCache(key,value);
    }
    else {
        list<pair<string, string>>::iterator mapVal;
        mapVal = map[key];
        if (value == mapVal->second) {
            return;
        }
        mapVal->second = key;
        // not sure if this is a requirement
        // updateRecentlyAccessed(map[key]);
    }
    time += this->writeTime;
    if (nextLevel) {
        nextLevel->writeKey(key, value, time);
    }
}

void Cache::printCacheContents() {
    cout << typeid(this).name() << " : ";
    for (auto node : lst) {
        cout << node.first << ":"<< node.second << "  ";
    }
    cout << endl;
    if (nextLevel) {
        nextLevel->printCacheContents();
    }
}

float Cache::getCurrentUsage() {
    return ((float)lst.size() / (float)capacity);
}

void Cache::printCacheUsage() {
    float usage = getCurrentUsage();
    cout << usage;
    if (nextLevel) {
        cout << " / ";
        nextLevel->printCacheUsage();
    }
}