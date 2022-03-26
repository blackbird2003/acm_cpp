//
// Created by vv123 on 2022/3/20.
//
#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;
    void print() {
        cout << real << "," << imag << endl;
    }
    Complex (double r, double i): real(r), imag(i) {}
    Complex addOne() {
        this->real++;
        this->print();
        return *this;
    }
};

int main() {
    Complex c1(0, 0), c2(1, 1);
    c2 = c1.addOne();
    return 0;
}


