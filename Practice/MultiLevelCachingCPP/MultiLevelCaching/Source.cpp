#include "Cache.h"
#include "L1Cache.h"
#include "L2Cache.h"
#include "L3Cache.h"
#include "MultiLevelCache.h"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

const string WHITESPACE = " \n\r\t\f\v";
void test1(MultiLevelCache* mlCache) {

    mlCache->writeOperation("abc", "apple");
    mlCache->writeOperation("def", "ball");
    mlCache->ReadOperation("abc");
    mlCache->print();
    mlCache->writeOperation("ghi", "cat");
    mlCache->writeOperation("jkl", "dog");
    mlCache->print();
    mlCache->writeOperation("mno", "elephant");
    mlCache->writeOperation("pqr", "fish");
    mlCache->print();
    mlCache->ReadOperation("jkl");
    mlCache->writeOperation("abc", "apple");
    mlCache->print();
    mlCache->printCacheUsage();

    /*
    mlCache->writeOperation("ghi", "cat");
    mlCache->writeOperation("ox", "cow");
    mlCache->writeOperation("parrot", "parakeet");
    mlCache->writeOperation("def", "ball");
    mlCache->printCacheUsage();
    cout << "Last 10 read average: " << mlCache->getLast10ReadAvg() << endl;
    cout << "Last 10 write average: " << mlCache->getLast10WriteAvg() << endl;
    */
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

void testWithHardcodedValues() {

    Cache* l3Cache = new L3Cache(10, 9, 15);
    Cache* l2Cache = new L2Cache(5, 3, 10, l3Cache);
    Cache* l1Cache = new L1Cache(2, 1, 5, l2Cache);

    MultiLevelCache* mlCache = new MultiLevelCache(l1Cache, l2Cache, l3Cache);
    test1(mlCache);

}

void testWithUserInput() {

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

    MultiLevelCache* mlCache = new MultiLevelCache(capacity, readTime, writeTime);
    test1(mlCache);
}

int main() {
    testWithHardcodedValues();
    //testWithUserInput();

    return 0;
}