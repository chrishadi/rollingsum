#include "rollingsum.hpp"

rollingsum::rollingsum(int cap) {
    if (cap > 0) {
        capacity = cap;
        elements = std::make_unique<int[]>(cap);
        count = 0;
        next_index = 0;
        total = 0;
    }
}

int rollingsum::add(int num) {
    if (!elements) {
        return 0;
    }

    if (count == capacity) {
        total -= elements[next_index];
    } else {
        count++;
    }

    elements[next_index++] = num;
    if (next_index == capacity) {
        next_index = 0;
    }

    total += num;
    return total;
}

int rollingsum::size() {
    return count;
}

int rollingsum::sum() {
    return total;
}

int rollingsum::operator<<(int num) {
    return add(num);
}
