#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 100003;


int qpow(ll x, ll y, int mod){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans % mod;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll m, n;
    cin >> m >> n;
    ll ans = qpow(m, n, mod) - m * qpow(m - 1, n - 1, mod);
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;

	return 0;
}
