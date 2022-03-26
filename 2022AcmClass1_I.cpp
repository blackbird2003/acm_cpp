//
// Created by vv123 on 2022/3/3.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 2e5 + 10;

struct Node {
    int val;
    int idx;
    Node *prev, *next;
};

Node *head, *tail;

void initialize() {
    head = new Node();
    tail = new Node();
    head -> next = tail;
    tail -> prev = head;
}

void insert(Node *p, int val, int idx) {
    Node *q = new Node();
    q -> val = val;
    q -> idx = idx;
    p -> next -> prev = q;
    q -> prev = p; q -> next = p -> next;
    p -> next = q;
}

void remove(Node *p) {
    p -> next -> prev = p -> prev;
    p -> prev -> next = p -> next;
    delete p;
}


int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        initialize();
        int m, n;
        cin >> m >> n;
        Node *p = head;
        for (int i = 1; i <= m; i++) {
            insert(p, i, i);
            p = p -> next;
        }
        tail -> prev -> next = head -> next;
        head -> next -> prev = tail -> prev;
        p = p -> next;
        for (int k = 1; k <= m - 1; k++) {
            for (int i = 1; i <= n; i++)
                p = p -> next;
            remove(p -> prev);
        }
        cout << p -> idx << "\n";
    }
    return 0;
}
