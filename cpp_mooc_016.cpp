//
// Created by vv123 on 2022/3/22.
//
#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point() { };
    friend istream& operator>>(istream& is, Point &p);
    friend ostream& operator<<(ostream& os, const Point &p);
};
istream& operator>>(istream& is, Point &p) {
    is >> p.x >> p.y;
    return is;
}
ostream& operator<<(ostream& os, const Point& p) {
    os << p.x << "," << p.y;
    return os;
}
int main()
{
    Point p;
    while(cin >> p) {
        cout << p << endl;
    }
    return 0;
}
