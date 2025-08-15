#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int t;

map<ll, int> mp;
map<ll, ll> mpa, mpc;

ll work(ll x,ll y,ll m){
    if(y == 1) return x;
    if(y == 0) return 1;
    ll tmp = work(x, y/2, m)%m;
    if(y % 2 == 1) return tmp * tmp %m *x %m;
    else return tmp * tmp%m;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        mp.clear(); mpa.clear(); mpc.clear();
        if(a == 0 || c == 0){cout << 0 << endl; continue;}
        ll gcd_ac = gcd(a, c);
        ll tmp = gcd_ac;
        for(ll i = 2; i * i <= tmp; i++){
            while(gcd_ac % i == 0){
                mp[i]++;
                gcd_ac /= i;
            }
        }
        if(gcd_ac > 1) mp[gcd_ac]++;
        

        for(auto it : mp){
            while(a % it.first == 0){
                mpa[it.first]++;
                a /= it.first;
            }
            while(c % it.first == 0){
                mpc[it.first]++;
                c /= it.first;
            }
        }
            
        b %= mod - 1;
        d %= mod - 1;
        ll ans = 1;

        for(auto it : mp){
            mpa[it.first] = mpa[it.first] * b % (mod - 1);
            mpc[it.first] = mpc[it.first] * d % (mod - 1);
            ans = ans * work(it.first, min(mpa[it.first], mpc[it.first]), mod) % mod;
        }

        cout << ans << endl;
        
    }

	return 0;
}
