// 线段树1.5
// 区间加，区间求和
// 动态开点
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int maxn = 1e5 + 500;

int n, m;
ll a[maxn];
int tot, root;

struct node{
    int ls, rs;
    ll lzy, w;
}tr[maxn * 160]; // tree
// * 4 * 40 = * 160; (40 系 n + m次log)

void pushup(int u){tr[u].w = tr[tr[u].ls].w + tr[tr[u].rs].w;}
bool inrange(int l, int r, int L, int R){return L <= l && r <= R;}
bool outofrange(int l, int r, int L, int R){return r < L || l > R;}

void maketag(int& u, int len, ll x){
    if(!u) u = ++tot;
    tr[u].lzy += x;
    tr[u].w += x * len;
}

void pushdown(int u, int l, int r){
    if(!u || !tr[u].lzy) return;
    int mid = (l + r) >> 1;
    maketag(tr[u].ls, mid - l + 1, tr[u].lzy);
    maketag(tr[u].rs, r - mid, tr[u].lzy);
    tr[u].lzy = 0;
}

void build(int& u, int l, int r){
    if(!u) u = ++tot;
    if(l == r){
        tr[u].w = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(tr[u].ls, l, mid);
    build(tr[u].rs, mid + 1, r);
    pushup(u);
}

ll ddcx(int u, int l, int r, int p){
    if(!u) return 0;
    if(l == r) return tr[u].w;
    int mid = (l + r) >> 1;
    pushdown(u, l, r);
    if(p <= mid) return ddcx(tr[u].ls, l, mid, p);
    else return ddcx(tr[u].rs, mid + 1, r, p);
}

void ddxg(int& u, int l, int r, int p, ll x){
    if(!u) u = ++tot;
    if(l == r){
        tr[u].w = x;
        tr[u].lzy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(u, l, r);
    if(p <= mid) ddxg(tr[u].ls, l, mid, p, x);
    else ddxg(tr[u].rs, mid + 1, r, p, x);
    pushup(u);
}

ll qjcx(int u, int l, int r, int L, int R){
    if(!u || outofrange(l, r, L, R)) return 0;
    if(inrange(l, r, L, R)) return tr[u].w;
    int mid = (l + r) >> 1;
    pushdown(u, l, r);
    return qjcx(tr[u].ls, l, mid, L, R) + qjcx(tr[u].rs, mid + 1, r, L, R);
}

void qjxg(int& u, int l, int r, int L, int R, ll x){
    if(outofrange(l, r, L, R)) return;
    if(!u) u = ++tot;
    if(inrange(l, r, L, R)){
        maketag(u, r - l + 1, x);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(u, l, r);
    qjxg(tr[u].ls, l, mid, L, R, x);
    qjxg(tr[u].rs, mid + 1, r, L, R, x);
    pushup(u);
}
ll getsum(int l, int r){
    return 1ll * (l + r) * (r - l + 1) / 2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    //for (int i = 1; i <= n; i++) a[i] = i;
    //build(root, 1, n);

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1){
            ll k;
            cin >> k;
            qjxg(root, 1, n, x, y, k);
        }
        else  cout << qjcx(root, 1, n, x, y) + getsum(x, y) << "\n";
        
    }

    return 0;
}
