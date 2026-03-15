#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 10;
ll inv[maxn], p, n, fac[maxn];

ll qpow(ll x, ll y, ll p){
    if(y == 0) return 1;
    if(y == 1) return x;
    ll tmp = qpow(x, y / 2, p) % p;
    if(y & 1) return tmp * x % p * tmp % p;
    else return tmp * tmp % p;
}

void pre(){
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
    
    inv[n] = qpow(fac[n], p - 2, p);

    for(int i = n - 1; i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> p;
    pre();

    for(int i = 1; i <= n; i++)
        cout << fac[i - 1] * inv[i] % p << "\n";

	return 0;
}
