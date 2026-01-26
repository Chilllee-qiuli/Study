#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
vector<ll> cur;
int n;

int main(){
    //freopen("t09.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    ll flag1 = 0;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        cur.push_back(x);
        flag1 ^= x;
    }

    ll pos = flag1 & (-flag1);

    ll fl0 = 0, fl1 = 0;
    for(auto u : cur){
        if(u & pos) fl1 ^= u;
        else fl0 ^= u;
    }

    if(fl0 > fl1) swap(fl1, fl0);

    cout << fl0 << " " << fl1 << "\n";

    



	return 0;
}