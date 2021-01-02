#include "L2Cache.h"

L2Cache::L2Cache(int capacity, int readTime, int writeTime, Cache* nextLevel) {

    this->capacity = capacity;
    this->readTime = readTime;
    this->writeTime = writeTime;
    this->nextLevel = nextLevel;
}