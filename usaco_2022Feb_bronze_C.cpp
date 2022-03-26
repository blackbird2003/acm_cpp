<<<<<<< HEAD
//
// Created by vv123 on 2022/2/26.
//
#include <bits/stdc++.h>
using namespace std;
int T;
string s[4], t;
int main() {
    cin >> T;
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    while (T--) {
        int a[] = {0, 1, 2, 3};
        cin >> t;
        do {
            bool flag = true;
            for (int i = 0; i < t.length(); i++)
                if (s[a[i]].find(t[i]) == s[a[i]].npos)
                    flag = false;
            if (flag) {
                puts("YES");
                goto loop;
            }
        } while (next_permutation(a, a + 4));
        puts("NO");
        loop:;
    }
    return 0;
}
=======
//
// Created by vv123 on 2022/2/26.
//
#include <bits/stdc++.h>
using namespace std;
int T;
string s[4], t;
int main() {
    cin >> T;
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    while (T--) {
        int a[] = {0, 1, 2, 3};
        cin >> t;
        do {
            bool flag = true;
            for (int i = 0; i < t.length(); i++)
                if (s[a[i]].find(t[i]) == s[a[i]].npos)
                    flag = false;
            if (flag) {
                puts("YES");
                goto loop;
            }
        } while (next_permutation(a, a + 4));
        puts("NO");
        loop:;
    }
    return 0;
}
>>>>>>> eb78ae3d1fc2d4b02f3e542cfe861cef6d785780
