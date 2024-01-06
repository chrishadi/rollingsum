#ifndef ROLLINGSUM_H
#define ROLLINGSUM_H

class rollingsum {
    public:
    rollingsum(int);
    ~rollingsum();
    void add(int);
    int size() { return count; };
    int sum() { return total; };

    private:
    int *elements;
    int capacity;
    int count;
    int next_index;
    int total;
};

#endif
