#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int n, k;
ll a[maxn];
int trie[maxn * 33][2];
int sz[maxn * 33];
int tot = 0;

void insert(ll val){
    int u = 0;
    for(int i = 31; i >= 0; i--){
        int z = (val >> i) & 1;
        if(!trie[u][z]) trie[u][z] = ++tot;
        u = trie[u][z];
        sz[u]++;
    }
}

ll find(ll val, int t){
    ll s = 0;
    int u = 0;
    for(int i = 31; i >= 0; i--){
        int z = (val >> i) & 1;
        if(sz[trie[u][z ^ 1]] >= t){
            u = trie[u][z ^ 1];
            s |= (1ll << i);
        }
        else {
            t -= sz[trie[u][z ^ 1]];
            u = trie[u][z];
        }
    }
    return s;
}



struct node{
    ll w;
    int x, y;
    // x 的第 y 大选择
    bool operator < (const node &A) const {
        return w < A.w;
    }
};

node d[maxn];
priority_queue<node> qu;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i-1];
    }

    for(int i = 0; i <= n; i++) insert(a[i]);
    k <<= 1;

    for(int i = 0; i <= n; i++){
        d[i].w = find(a[i], 1);
        d[i].x = i;
        d[i].y = 1;
        qu.push(d[i]);
    }

    ll ans = 0;
    node A;
    for(int i = 1; i <= k; i++){
        A = qu.top();
        ans += A.w;
        qu.pop();
        d[A.x].y++;
        d[A.x].w = find(a[A.x], d[A.x].y);
        qu.push(d[A.x]);
    }

    ans >>= 1;
    cout << ans << endl;


	return 0;
}
