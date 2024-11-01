#include "array_operations.hh"

int greatest_v1(int* itemptr, int size) {
    int greatest = *itemptr;
    for (int i = 1; i < size; ++i) {
        if (*(itemptr + i) > greatest) {
            greatest = *(itemptr + i);
        } }
    return greatest;
}
int greatest_v2(int* itemptr, int* endptr) {
    int greatest = *itemptr;
    for (int* ptr = itemptr; ptr < endptr; ++ptr) {
        if (*ptr > greatest) {
            greatest = *ptr;
        }
    }
    return greatest;
}
void copy(int* itemptr, int* endptr, int* targetptr) {
    for (int* ptr = itemptr; ptr < endptr; ++ptr) {
        *targetptr = *ptr;
        targetptr++;
    }
}
void reverse(int* leftptr, int* rightptr) {
    rightptr--;
    while (leftptr < rightptr) {
        int temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;
        leftptr++;
        rightptr--;
    }
}
