//
// Created by vv123 on 2022/3/22.
//
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt {
    char buf[210];
public:
    void reverse(char* p) {
        int len = strlen(p);
        for (int i = 0; i < len - i - 1; i++)
            swap(p[i], p[len - i - 1]);
    }
    CHugeInt(char* p) {
        memset(buf, 0, sizeof buf);// \0的ASCII码是0
        strcpy(buf, p);
        reverse(buf);
    }
    CHugeInt(int n) {
        memset(buf, 0, sizeof buf);
        sprintf(buf, "%d", n);
        reverse(buf);
    }
    CHugeInt operator+(const CHugeInt& n) const {
        CHugeInt tmp(0);
        int k = 0;//进位
        for (int i = 0; i < 210; i++) {
            if (!k && !buf[i] && !n.buf[i]) break;
            int x = buf[i] ? buf[i] - '0' : 0, y = n.buf[i] ? n.buf[i] - '0' : 0;
            int t = x + y + k;
            k = t / 10;
            tmp.buf[i] = t % 10 + '0';
        }
        return tmp;
    }
    CHugeInt operator+(int n) {
        return *this + CHugeInt(n);
    }
    friend CHugeInt operator+(int n, const CHugeInt& m) {
        return m + n;
    }
    friend ostream& operator<<(ostream& os, const CHugeInt& n) {
        for (int i = strlen(n.buf) - 1; i >= 0; i--) {
            os << n.buf[i];
        }
        return os;
    }
    CHugeInt& operator++() {
        *this = *this + 1;
        return *this;
    }
    CHugeInt operator++(int) {
        CHugeInt tmp(*this);
        *this = *this + 1;
        return tmp;
    }
    CHugeInt& operator+=(int n) {
        *this = *this + n;
        return *this;
    }
};
int  main()
{
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}

