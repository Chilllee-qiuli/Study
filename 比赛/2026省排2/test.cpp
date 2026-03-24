#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll qpow(ll x, ll y){
    ll tmp = x, ans = 1;
    while(y){
        if(y & 1) ans *= tmp;
        tmp = tmp * tmp % mod;
        y >>= 1;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cout << qpow(2, 10);


    return 0;
}