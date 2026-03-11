// 线段树1
// 区间加，区间求和
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 500;
ll w[maxn * 4], a[maxn], lzy[maxn];
int n, m;

void pushup(int u){w[u] = w[u << 1] + w[u << 1 | 1];}
bool inrange(int l, int r, int L, int R){return L <= l && r <= R;}
bool outofrange(int l, int r, int L, int R){return r < L || l > R;}

void maketag(int u, int len, ll x){
    lzy[u] += x;
    w[u] += x * len;
}
void pushdown(int u, int l, int r){
    if(lzy[u]){
        int mid = l + r >> 1;
        maketag(u << 1, mid - l + 1, lzy[u]);
        maketag(u << 1 | 1, r - mid, lzy[u]);
        lzy[u] = 0;
    }
}
void build(int u, int l, int r){
    if(l == r){
        w[u] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

ll ddcx(int u, int l, int r, int p){
    if(l == r) return w[u];
    int mid = l + r >> 1;
    pushdown(u, l ,r);
    if(p <= mid) return ddcx(u << 1, l, mid, p);
    else return ddcx(u << 1 | 1, mid + 1, r, p);
}
void ddxg(int u, int l, int r, int p, ll x){
    if(l == r) {
        w[u] += x;
        return;
    }
    int mid = l + r >> 1;
    pushdown(u, l, r);
    if(p <= mid) ddxg(u << 1, l, mid, p, x);
    else ddxg(u << 1 | 1, mid + 1, r, p, x);
    pushup(u);
}
ll qjcx(int u, int l, int r, int L, int R){
    if(inrange(l, r, L, R)) return w[u];
    else if(outofrange(l, r, L, R)) return 0;
    else {
        int mid = l + r >> 1;
        pushdown(u, l, r);
        return qjcx(u << 1, l, mid, L, R) + qjcx(u << 1 | 1, mid + 1, r, L, R);
    }
}
void qjxg(int u, int l, int r, int L, int R, ll x){
    if(inrange(l, r, L, R)) maketag(u, r - l + 1, x);
    else if(!outofrange(l, r, L, R)){
        int mid = l + r >> 1;
        pushdown(u, l, r);
        qjxg(u << 1, l, mid, L, R, x);
        qjxg(u << 1 | 1, mid + 1, r, L, R, x);
        pushup(u);
    }
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1){
            ll k;
            cin >> k;
            qjxg(1, 1, n, x, y, k);
        }
        else cout << qjcx(1, 1, n, x, y) << "\n";
    }

    return 0;
}
