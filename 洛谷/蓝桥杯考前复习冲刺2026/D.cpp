#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll qpow(ll a, ll b, ll p){
    ll tmp = 1;
    while(b){
        if(b & 1) tmp = tmp * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return tmp;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll a, b, p;
    cin >> a >> b >> p;

    printf("%lld^%lld mod %lld=%lld\n", a, b, p, qpow(a, b, p));
    

    

    return 0;
}