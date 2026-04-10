#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int> 
#define mk make_pair
const int all = 5e5 + 10;
const int mod = 1000000007;
int a[all], tot;
ll fac[all], inv[all];


vector<int> nums;
vector<pr> mtr;

ll qpow(ll x, ll y){
    if(y == 0) return 1;
    if(y == 1) return x;
    ll tmp = qpow(x, y / 2);
    if(y & 1) return tmp * tmp % mod * x % mod;
    else return tmp * tmp % mod;
 }

void pre(){
    fac[1] = 1;
    for(int i = 2; i < all; i++)
    fac[i] = fac[i - 1] * i % mod;

    inv[500000 + 2] = qpow(fac[500000 + 2], mod - 2);
    for(int i = 500001; i >= 1; i--){
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }

}

void dfs(int u, int now){
    if(u >= nums.size()){
        int nm = tot - 2;
        mtr.push_back(mk(now, nm / now));
        return ;
    }
    dfs(u + 1, now);
    dfs(u + 1, now * nums[u]);
}

int cnt[all];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();
    cin >> tot;
    for(int i = 1; i <= tot; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    

    int nm = tot - 2;
    for(int i = 2; i * i <= tot - 2; i++){
        while(nm % i == 0){
            nm /= i;
            nums.push_back(i);
        }
        if(nm == 1) break;
    }
    if(nm != 1) nums.push_back(nm);

    dfs(0, 1);

    sort(mtr.begin(), mtr.end());
    mtr.erase(unique(mtr.begin(), mtr.end()), mtr.end());

    ll tmp = fac[tot - 2];
    fac[0] = 1;
    inv[0] = 1;

    for(int i = 1; i < all; i++)
        tmp = tmp * inv[cnt[i]] % mod;


    ll ans = 0;
    for(auto [n, m] : mtr){

        if(n == m){
            ll nmp = tmp * fac[cnt[n]] % mod;
            nmp = nmp * inv[cnt[n] - 2] % mod;
            ans = (ans + nmp) % mod;
            continue;
        }
        ll nmp = tmp * fac[cnt[n]] % mod * fac[cnt[m]] % mod;
        nmp = nmp * inv[cnt[n] - 1] % mod * inv[cnt[m] - 1] % mod;
        ans = (ans + nmp) % mod;

    }

    cout << ans << endl;

	return 0;
}
