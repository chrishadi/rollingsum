#include "rollingsum.h"

rollingsum::rollingsum(int cap) {
    if (cap > 0) {
        capacity = cap;
        elements = std::make_unique<int[]>(cap);
        count = 0;
        next_index = 0;
        total = 0;
    }
}

void rollingsum::add(int num) {
    if (!elements) {
        return;
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
}

void rollingsum::operator<<(int num) {
    add(num);
}
