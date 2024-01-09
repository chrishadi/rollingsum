#ifndef ROLLINGSUM_H
#define ROLLINGSUM_H

#include <memory>

class rollingsum {
    public:
    rollingsum(int);
    int add(int);
    int size() { return count; };
    int sum() { return total; };
    int operator<<(int);

    private:
    std::unique_ptr<int[]> elements;
    int capacity;
    int count;
    int next_index;
    int total;
};

#endif
