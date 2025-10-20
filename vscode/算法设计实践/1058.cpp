#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll work(ll a, ll b, ll p){
    if(b == 0) return 1;
    if(b == 1) return a;
    ll tmp = work(a, b >> 1, p);
    tmp = tmp * tmp % p;
    if(b & 1) return tmp * a % p;
    else return tmp;
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll a, b, p;
    cin >> a >> b >> p;
    cout << work(a, b, p) % p << endl;

	return 0;
}