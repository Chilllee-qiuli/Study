#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int n, m;
ll tr[maxn];

void add1(int x, ll y){
    for(; x < maxn; x += x & -x) tr[x] ^= y;
}
ll find1(int x){
    ll ans = 0;
    for(; x; x -= x & -x) ans ^= tr[x];
    return ans;
}

ll all[maxn];
void add2(int x, ll y){
    for(; x < maxn; x += x & -x) all[x] ^= y;
}
ll find2(int x){
    ll ans = 0;
    for(; x; x -= x & -x) ans ^= all[x];
    return ans;
}


unordered_map<int, int> pos;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        add1(i, x);
        if(pos[x]) add2(pos[x], x);
        
        add2(i, x);
        pos[x] = i ;
    }

    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        ll tmp1 = find2(r) ^ find2(l - 1);
        ll tmp2 = find1(r) ^ find1(l - 1);
        cout << ( tmp1 ^ tmp2) << endl;
    }

    return 0;
}