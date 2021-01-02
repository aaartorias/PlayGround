#include "MultiLevelCache.h"


MultiLevelCache::MultiLevelCache(const vector<int>& capacity, const vector<int>& readTime, const vector<int>& writeTime) {
	l3Cache = new L3Cache(capacity[2], readTime[2], writeTime[2]);
	l2Cache = new L2Cache(capacity[1], readTime[1], writeTime[1], l3Cache);
	l1Cache = new L1Cache(capacity[0], readTime[0], writeTime[0], l2Cache);
}

MultiLevelCache::MultiLevelCache(Cache* l1Cache, Cache* l2Cache, Cache* l3Cache) {
	this->l3Cache = l3Cache;
	this->l2Cache = l2Cache;
	this->l1Cache = l1Cache;
}


void MultiLevelCache::writeOperation(string key, string value) {
	int writeTime = 0;
	l1Cache->writeKey(key, value, writeTime);
	writeList.push_back(writeTime);
	std::cout << "Write time: " << writeTime << endl;
}

void MultiLevelCache::ReadOperation(string key) {
	int readTime = 0;
	string value = l1Cache->readKey(key, readTime);
	if (value == "") {
		cout << "Key: " << key << " doesn't exist in cache" << endl;
	}
	else {
		cout << "Key: " << key << " Value: " << value << endl;
		std::cout << "Read time: " << readTime << endl;
		readList.push_back(readTime);
	}
}

void MultiLevelCache::print() {
	l1Cache->printCacheContents();
}

float MultiLevelCache::getLast10AgvTime(list<int>& timeList) {
	if (timeList.size() > 10) {
		while (timeList.size() != 10) {
			timeList.pop_front();
		}
	}

	float totalTime = 0;
	for (auto time : timeList) {
		totalTime += time;
	}
	float avgTime = totalTime / 10;
	return avgTime;
}

float MultiLevelCache::getLast10ReadAvg() {
	if (readList.size() < 10) {
		cout << "Invalid operation: Reads are less than 10" << endl;
		return -1;
	}

	return getLast10AgvTime(readList);
}

float MultiLevelCache::getLast10WriteAvg() {

	if (writeList.size() < 10) {
		cout << "Invalid operation: Writes are less than 10" << endl;
		return -1;
	}

	return getLast10AgvTime(writeList);
}

void MultiLevelCache::printCacheUsage() {
	l1Cache->printCacheUsage();
}


