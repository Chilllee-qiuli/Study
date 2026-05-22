#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2020;
const int maxm = 4e6 + 120;
const int mod = 998244353;
int n;
ll a[maxn], b[maxn];


ll tr[maxm];
vector<ll> tmp;

ll fac[maxn], inv[maxn];

void pre(){
    inv[1] = 1;
    ll p = mod;
    for (int i = 2; i < maxn; i++)
    inv[i] = p - (p / i) * inv[p % i] % p;

    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
}

void add(int i, int x){
    for(; i < maxm; i += i & (-i)) tr[i] += x;
}

ll find(int i){
    ll tmp = 0;
    for(; i; i -= i & -i) tmp += tr[i];
    return tmp;
}

int fidx(ll x){
    return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
}
ll c[maxm];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    pre();
    while(t--){
        cin >> n;

        vector<ll> ().swap(tmp);
        tmp.push_back(-1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];


        ll kkk = 0;
        for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        if(a[i] > a[j]) kkk++;


        ll kkkb = 0;
        for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        if(b[i] > b[j]) kkkb++;


        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            tmp.push_back(a[i] * b[j]);

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        int tot = 0;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        c[++tot] = fidx(a[i] * b[j]); 

        for(int i = 1; i <= tmp.size(); i++) tr[i] = 0;

        ll ans = 0;
        for(int i = 1; i <= tot; i++){
            ans += (i - 1) - find(c[i]);
            ans %= mod;
            add(c[i], 1);
        }
        ans -= kkk * n % mod;
        ans -= kkkb * n % mod;
        ans = (ans % mod + mod) % mod;
        
        cout << ans % mod * inv[n] % mod * inv[n-1] % mod << endl;
        
    }

	return 0;
}
