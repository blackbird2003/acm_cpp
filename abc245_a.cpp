#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a != c) {
        a < c ? puts("Takahashi") : puts("Aoki");
    } else {
        b <= d ? puts("Takahashi") : puts("Aoki");
    }
    return 0;
}
