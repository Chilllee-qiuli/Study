#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const ll mod = 998244353;
int T;
int n;
int fa[maxn], vis[maxn];
vector<ll> vc;

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
    cin >> T ;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> fa[i];
            vis[i] = 0;
        }
        ll odd = 0, even_4 = 0, even_2 = 0;
        ll ans = 0;
        vc.clear();

        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            ll sz = 1; // size;
            vis[i] = 1;
            for(int x = fa[i]; x != i; x = fa[x]) {vis[x] = 1; sz++;}
            if(sz & 1) {
                odd++;
                if(odd <= 2) vc.push_back(sz);
            }
            else {    
                if(sz > 2) even_4++, ans += sz*sz/4;
                else even_2++;
            }
            
            ans %= mod;
            
        }
        ll other = work(2, even_4, mod);
        if(odd == 2) cout << (vc[0] * vc[1]) % mod * other % mod << endl;        
        else if(odd == 0) {
            // cout << (ans * other / 2 % mod + even_2 * other) % mod << endl;
            ans = other * (mod + 1) / 2 % mod * ans % mod;
            ans += even_2 * other % mod;
            cout << ans % mod << endl;
        }
        else cout << 0 << endl;
    }   


	return 0;
}
