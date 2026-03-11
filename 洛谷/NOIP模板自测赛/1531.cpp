
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 500;
ll w[maxn * 4], a[maxn], lzy[maxn];
int n, m;

void pushup(int u){w[u] = max(w[u << 1], w[u << 1 | 1]);}
bool inrange(int l, int r, int L, int R){return L <= l && r <= R;}
bool outofrange(int l, int r, int L, int R){return r < L || l > R;}


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

void ddxg(int u, int l, int r, int p, ll x){
    if(l == r) {
        w[u] = x;
        return;
    }
    int mid = l + r >> 1;

    if(p <= mid) ddxg(u << 1, l, mid, p, x);
    else ddxg(u << 1 | 1, mid + 1, r, p, x);
    pushup(u);
}
ll qjcx(int u, int l, int r, int L, int R){
    if(inrange(l, r, L, R)) return w[u];
    else if(outofrange(l, r, L, R)) return 0;
    else {
        int mid = l + r >> 1;
        return max(qjcx(u << 1, l, mid, L, R), qjcx(u << 1 | 1, mid + 1, r, L, R));
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    while (m--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if(op == 'Q') cout << qjcx(1, 1, n, l, r) << "\n";
        else if(a[l] < r) {
            ddxg(1, 1, n, l, r);
            a[l] = r;
        }

    }

    return 0;
}
