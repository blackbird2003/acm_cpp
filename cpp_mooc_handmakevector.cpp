//
// Created by vv123 on 2022/3/21.
//
#include <iostream>
#include <cstring>

using namespace std;

class myVector {
    int capacity;
    int size;
    int *ptr;
public:
    myVector(int s = 0);
    myVector(myVector &a);
    ~myVector();
    void push_back(int v);
    void pop_back();
    myVector& operator= (const myVector &a);
    int length() { return size; }
    int volume() { return capacity; }
    bool empty() { return size == 0; }
    int& operator[] (int i) {
        return ptr[i];
    }
    void print();
};
//constructor
myVector::myVector(int s):size(s), capacity(max(s, 1)) {
    ptr = s ? new int[capacity] : NULL;
}
//copy constructor
myVector::myVector(myVector &a) {
    if (!a.ptr) {
        ptr == NULL;
        size == 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}
//destructor
myVector::~myVector() {
    if(ptr)
        delete[] ptr;
}
//operator=
myVector& myVector::operator=(const myVector &a) {
    if (ptr == a.ptr)
        return *this;
    if (a.ptr == NULL) {
        if (ptr) delete[] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if (capacity < a.size) {
        if(ptr)
            delete[] ptr;
        while (capacity < a.size)
            capacity *= 2;
        ptr = new int[capacity];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}
//push_back
void myVector::push_back(int v) {
    if (!ptr)
        ptr = new int[1];
    else if (size + 1 > capacity) {
        capacity *= 2;
        int *tmpPtr = new int[capacity];
        memcpy(tmpPtr, ptr, sizeof(int) * size);
        delete[] ptr;
        ptr = tmpPtr;
    }
    ptr[size++] = v;
}
//pop_back
void myVector::pop_back() {
    if (!size) return;
    size--;
    if (!size) ptr = NULL;
}
//print
void myVector::print() {
    printf("size=%d capacity=%d\ncontent:", length(), volume());
    for (int i = 0; i < length(); i++)
        printf("%d ", (*this)[i]);
    if (empty()) printf("empty");
    puts("");
}
int main() {
    myVector a;
    a.print();
    int n;
    while(cin >> n) {
        if (n == -1) a.pop_back();
        else a.push_back(n);
        a.print();
    }
    return 0;
}
