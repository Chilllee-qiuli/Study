#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mmod = 19260817;

ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + (ch - '0');
        x %= mmod;
        ch = getchar();
    }
    return x * f;
}

ll qpow(ll a, ll b, ll mod){
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    ll res = qpow(a, b >> 1, mod);
    res = res * res % mod; 
    if(b & 1) res = res * a % mod;
    return res;
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    ll a = read(), b = read();
    if(!b){
        cout << "Angry!" << endl;
        return 0;
    }
    b = qpow(b, mmod - 2, mmod); // 计算b的逆元
    cout << (a * b) % mmod << endl;

	return 0;
}
