#include "L1Cache.h"

L1Cache::L1Cache(int capacity, int readTime, int writeTime, Cache* nextLevel) {

    this->capacity = capacity;
    this->readTime = readTime;
    this->writeTime = writeTime;
    this->nextLevel = nextLevel;
}