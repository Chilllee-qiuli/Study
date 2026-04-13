#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll a[maxn];
int n, m;
ll w[maxn * 4], tag[maxn * 4];

void pushup(int u){
    w[u] = w[u << 1] + w[u << 1 | 1];
}

bool inrange(int L, int R, int l, int r){return l <= L && R <= r;}
bool outofrange(int L, int R, int l, int r){return R < l || r < L;}
void maketag(int u, int l, int r, ll x){
    tag[u] += x;
    w[u] += x * (r - l + 1);
}

void pushdown(int u, int l, int r){
    if(tag[u]){
        int mid = (l + r) >> 1;
        maketag(u << 1, l, mid, tag[u]);
        maketag(u << 1 | 1, mid + 1, r, tag[u]);
        tag[u] = 0;
    }
}

void build(int u, int L, int R){
    if(L == R){
        w[u] = a[L];
        return ;
    }
    int mid = (L + R) >> 1;
    build(u << 1, L, mid);
    build(u << 1 | 1, mid + 1, R);
    pushup(u);
}

void qjxg(int u, int L, int R, int l, int r, ll x){
    if(inrange(L, R, l, r)) return maketag(u, L, R, x);
    else if(!outofrange(L, R, l, r)){
        int mid = (L + R) >> 1;
        pushdown(u, L, R);
        qjxg(u << 1, L, mid, l, r, x);
        qjxg(u << 1 | 1, mid + 1, R, l, r, x);
        pushup(u);
    }
}

ll qjcx(int u, int L, int R, int l, int r){
    if(inrange(L, R, l, r)) return w[u];
    else if(outofrange(L, R, l, r)) return 0;
    pushdown(u, L, R);
    int mid = (L + R) >> 1;
    return qjcx(u << 1, L, mid, l, r) + qjcx(u << 1 | 1, mid + 1, R, l, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    for(int i = 1; i <= m; i++){
        int op, x, y;
        ll k;
        cin >> op >> x >> y;
        if(op == 1){
            cin >> k;
            qjxg(1, 1, n, x, y, k);
        }
        else cout << qjcx(1, 1, n, x, y) << "\n";
    }


	return 0;
}
