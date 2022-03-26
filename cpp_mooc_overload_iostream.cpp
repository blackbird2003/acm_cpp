//
// Created by vv123 on 2022/3/21.
//
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0):real(i),imag(i) {};
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is,Complex& c);
    operator double() { return real; } //类型转换运算符
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << "+" << c.imag << "i";
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    string s;
    is >> s;
    int pos = s.find("+",0);
    string sTmp = s.substr(0, pos);
    c.real = atof(sTmp.c_str());
    sTmp = s.substr(pos + 1, s.length() - pos - 2);
    c.imag = atof(sTmp.c_str());
    return is;
}

int main() {
    Complex c;
    double n;
    cin >> c >> n;
    cout << c << "," << n << endl;
    cout << 2 + c << endl;//隐式类型转换
    return 0;
}
