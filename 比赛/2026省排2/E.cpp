#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 2010;
int n, m;

const int maxd = 2021;
ll c[maxd], inv[maxd];

ll qpow(ll x, ll y){
    ll tmp = x, ans = 1;
    while(y){
        if(y & 1) ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        y >>= 1;
    }
    return ans % mod;
}

void pre(){
    c[0] = 1;
    c[1] = 1;
    for(int i = 2; i < maxd; i++)
        c[i] = i * c[i - 1] % mod;
    
    inv[2011] = qpow(c[2011], mod - 2);

    for(int i = 2010; i; i--){
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    inv[0] = 1;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    pre();

    ll ans = c[n - 1 + 2 * m] * inv[n - 1] % mod * inv[2 * m] % mod;
     
    ans = (ans + mod) % mod;

    cout << ans << endl;

    



    return 0;
}