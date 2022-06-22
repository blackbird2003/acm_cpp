//
// Created by vv123 on 2022/4/25.
//
#include <bits/stdc++.h>
using namespace std;

//#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<15,stdin),frS==frT)?EOF:*frS++)
//char frBB[1<<15],*frS=frBB,*frT=frBB;
template<typename T>
inline void read(T &x){
    x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
}

const int N = 1e5 + 10, INF = 0x3f3f3f3f, MAXX = 1e7;


struct node {
    int l, r, key, val, cnt, size;
} tr[N];
#define ls tr[p].l
#define rs tr[p].r
int n, root, idx;

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

void build() {
    get_node(-INF); get_node(INF);
    root = 1; tr[1].r = 2;
}
/*
   x      ->zig          y
  /                       \
 y                         x
  \                       /
   z      <-zag          z
 */
inline void zig(int& x) {
    int y = tr[x].l;
    tr[x].l = tr[y].r, tr[y].r = x, x = y;
    pushup(tr[x].r), pushup(x); //注意这里的x是zig后的y QAQ
}
inline void zag(int& y) {
    int x = tr[y].r;
    tr[y].r = tr[x].l, tr[x].l = y, y = x;
    pushup(tr[y].l), pushup(y); //注意这里的y是zag后的x QAQ
}
void insert(int& p, int key) {
    if (!p) p = get_node(key);
    else if (key == tr[p].key) tr[p].cnt++;
    else if (key < tr[p].key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);//1.插入时维护堆性质
    }
    else if (key > tr[p].key) {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
    pushup(p);
}
void remove(int& p, int key) {
    if (!p) return;
    if (key == tr[p].key) {
        if (tr[p].cnt > 1) tr[p].cnt--;
        else {  //正式删除
            if (tr[p].l || tr[p].r) {   //不是叶节点，旋成叶节点后删除QAQ
                if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val)//2.删除时维护堆性质QAQ
                    zig(p), remove(tr[p].r, key);
                else zag(p), remove(tr[p].l, key);//注意:p的值会被改变，使其保持在原来的"位置"QAQ
            }
            else p = 0;//是叶节点，则使其祖先指向一个不会被访问的结点QAQ
        }
    }
    else {
        if (key < tr[p].key) remove(tr[p].l, key);
        else remove(tr[p].r, key);
    }
    pushup(p);//任何修改操作都别忘了pushup QAQ
}
int get_rank_by_key(int p, int key) {
    if (!p) return 0;
    if (key == tr[p].key) return tr[tr[p].l].size + 1;
    if (key < tr[p].key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size  + tr[p].cnt + get_rank_by_key(tr[p].r, key);
}
int get_key_by_rank(int p, int rank) {
    if (!p) return INF;
    if (rank <= tr[tr[p].l].size) return get_key_by_rank(tr[p].l, rank);
    if (rank <= tr[tr[p].l].size + tr[p].cnt) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}
int get_prev(int p, int key) {
    if (!p) return -INF;
    if (key <= tr[p].key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));//左<tr[p].key<key,无需在左子树中找
}
int get_next(int p, int key) {
    if (!p) return INF;
    if (key >= tr[p].key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));//右>tr[p].key>key,无需在右子树中找
}

int main() {
    build();
    scanf("%d", &n);
    while (n--) {
        int op, x, t;
        scanf("%d%d", &op, &x);
        if (op == 1) insert(root, x);
        else if (op == 2) remove(root, x);
        else if (op == 3) printf("%d\n", get_rank_by_key(root, x) - 1);//注意树上有—INF哨兵
        else if (op == 4) printf("%d\n", get_key_by_rank(root, x + 1));
        else if (op == 5) (t = get_prev(root, x)) < -MAXX ? puts("NOT FOUND") : printf("%d\n", t);
        else if (op == 6) (t = get_next(root, x)) > MAXX ? puts("NOT FOUND") : printf("%d\n", t);
    }
    return 0;
}