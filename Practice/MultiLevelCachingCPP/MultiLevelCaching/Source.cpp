#include "Cache.h"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

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