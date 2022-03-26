//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

struct Fraction {
    int a, b;
    Fraction operator + (const Fraction x) {
        Fraction res;
        res.b = lcm(b, x.b);
        res.a = a * res.b / b + x.a * res.b / x.b;
        int k = gcd(abs(res.a), res.b);
        res.a /= k; res.b /= k;
        return res;
    }
    Fraction operator * (const Fraction x) {
        Fraction res;
        res.a = a * x.a; res.b = b * x.b;
        int k = gcd(abs(res.a), res.b);
        res.a /= k; res.b /= k;
        return res;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        Fraction x, y, ans;
        char op;
        scanf("%d %d %d %d %c", &x.a, &x.b, &y.a, &y.b, &op);
        printf("%d/%d%c%d/%d=", x.a, x.b, op, y.a, y.b);
        if (op == '+') {
            ans = x + y;
        } else if (op == '-') {
            y.a = -y.a;
            ans = x + y;
        } else if (op == '*') {
            ans = x * y;
        } else {
            swap(y.a, y.b);
            ans = x * y;
        }
        if (ans.b == 1) printf("%d\n", ans.a);
        else printf("%d/%d\n", ans.a, ans.b);
    }
    return 0;
}

