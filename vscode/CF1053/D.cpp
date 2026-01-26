#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int mod = 998244353;
int t;
int n, a[maxn];
ll fac[maxn]; // factorial
ll inv[maxn]; // 逆元
int add[maxn];
ll pow(ll x, ll y, int p = 998244353){
    ll tmp = 1;
    for(; y; y >>= 1){
        if(y & 1) tmp = tmp * x % p;
        x = x * x % p;
    }
    return tmp % p;
}

void pre(){
    fac[0] = 1;

    for(int i = 1; i <= maxn - 5; i++){
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxn - 5] = pow(fac[maxn - 5], mod - 2, mod);

    for(int i = maxn - 6; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    
}
ll cxy(int x, int y){
    if (y < 0 || y > x) return 0;
    return fac[x] * inv[y] * inv[x - y] % mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    pre();
    while(t--){
        cin >> n;
        int tmp = 0;
        for(int i = 1; i <= n; i++) {
            add[i] = 0;
            cin >> a[i];
            tmp += a[i];
        }
        if(tmp != n) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 1;
        int nowa = 0, cnt = 0;
        for(int i = n; i; i--){
            int add_a = 0;
            if(i <= n/2){
                add_a = 2;
            }
            else if(n % 2 == 1 && i == (n + 1) / 2) add_a = 1;
            cnt += add_a;
            if(a[i] > cnt){
                ans = 0;
                break;
            }
            ans *= cxy(cnt, a[i]) % mod;
            cnt -= a[i];
        }   

        cout << ans << endl;


        
    }


	return 0;
}
