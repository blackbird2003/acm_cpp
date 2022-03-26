#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
    char * p;
public:
    MyString(const char * s) {
        puts("1 called");
        if(s) {
            p = new char[strlen(s) + 1];
            strcpy(p,s);
        }
        else
            p = NULL;

    }
    ~MyString() { if(p) delete [] p; }
    MyString(const MyString& s) {
        puts("2 called");
        if (s.p) {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        } else
            p = NULL;
    }
    void Copy(const char *s) {
        puts("3 called");
        delete[] p;
        if (!s) p = NULL;
        else {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        }
    }
    MyString& operator=(const char *s) {
        puts("4 called");
        delete[] p;
        if (s) {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        } else
            p = NULL;
        return *this;
    }

    MyString& operator=(const MyString& s) {
        puts("5 called");
        if (this == &s) return *this;
        delete[] p;
        if (s.p) {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        } else
            p = NULL;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const MyString& s);
};
ostream& operator<<(ostream& os, const MyString& s) {
    os << s.p;
    return os;

};
int main()
{
    char w1[200],w2[100];
    while( cin >> w1 >> w2) {
        puts("in");
        MyString s1(w1),s2 = s1;
        puts("out");
        MyString s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;

        s2 = w2;
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;

    }
}