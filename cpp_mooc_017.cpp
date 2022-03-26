//
// Created by vv123 on 2022/3/22.
//
#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
    int array[10][10];
public:
    Array2(int a = 0, int b = 0) {
        memset(array, 0, sizeof array);
    }
    Array2(Array2 &x) {
        memcpy(array,x.array, sizeof array);
    }
    int* operator[](int i) {
        return array[i];
    }
    int operator()(int i, int j) {
        return array[i][j];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
