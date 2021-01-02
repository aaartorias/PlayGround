#include "L3Cache.h"

L3Cache::L3Cache(int capacity, int readTime, int writeTime, Cache* nextLevel = nullptr) {

    this->capacity = capacity;
    this->readTime = readTime;
    this->writeTime = writeTime;
    this->nextLevel = nextLevel;
}