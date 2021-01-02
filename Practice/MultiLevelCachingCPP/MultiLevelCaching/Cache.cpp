#include "Cache.h"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

Cache::Cache(int capacity, int readTime, int writeTime, Cache* nextLevel = nullptr) {

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

string Cache::readKey(string key) {

    if (map.find(key) == map.end()) {

        string value;
        if (nextLevel) {
            value = nextLevel->readKey(key);
        }
        else {
            return "";
        }
        if (value == "") {
            return "";
        }
        else {
            insertInCache(key, value);
            return value;
        }
    }
    else {
        updateRecentlyAccessed(map[key]);
        return map[key]->second;
    }
}

void Cache::writeKey(string key, string value) {
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

    if (nextLevel) {
        nextLevel->writeKey(key, value);
    }
}

void convertInputSringToVector(const string& input, vector<int>& result) {

    istringstream iss(input);
    string element;
    for (element; iss >> element;) {
        result.push_back(stoi(element));
    }

}

void display(const vector<int>& result) {

    for (auto element : result) {
        cout << element << " -- ";
    }
    cout << endl;
}

int main() {

    int numberOfCache;
    string capacityString;
    string readTimeString;
    string writeTimeString;
    vector<int> capacity;
    vector<int> readTime;
    vector<int> writeTime;


    cin >> numberOfCache;
    cin.ignore();
    getline(cin, capacityString);
    getline(cin, readTimeString);
    getline(cin, writeTimeString);

    convertInputSringToVector(capacityString, capacity);
    convertInputSringToVector(readTimeString, readTime);
    convertInputSringToVector(writeTimeString, writeTime);

    display(capacity);
    display(readTime);
    display(writeTime);

    return 0;
}

