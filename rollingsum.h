#ifndef ROLLINGSUM_H
#define ROLLINGSUM_H

#include <memory>

class rollingsum {
    public:
    rollingsum(int);
    void add(int);
    int size() { return count; };
    int sum() { return total; };

    private:
    std::unique_ptr<int[]> elements;
    int capacity;
    int count;
    int next_index;
    int total;
};

#endif
