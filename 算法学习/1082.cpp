#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll exgcd(ll a, ll b, ll &x, ll &y){ // ax + by = gcd(a, b)
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll a, b;
    cin >> a >> b;
    ll x, y;
    ll d = exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl; // 注意x可能为负数，输出时需要调整为正数

	return 0;
}
