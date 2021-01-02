#pragma once

#include "Cache.h";
#include "L1Cache.h";
#include "L2Cache.h";
#include "L3Cache.h";

class MultiLevelCache
{

private:

	Cache* l1Cache;
	Cache* l2Cache;
	Cache* l3Cache;
	list<int> readList;
	list<int> writeList;
	float getLast10AgvTime(list<int>& list);

public:

	MultiLevelCache(const vector<int>& capacity, const vector<int>& readTime, const vector<int>& writeTime);
	MultiLevelCache(Cache* l1Cache, Cache* l2Cache, Cache* l3Cache);
	void ReadOperation(string key);
	void writeOperation(string key, string value);
	void print();
	float getLast10ReadAvg();
	float getLast10WriteAvg();
	void printCacheUsage();
};

