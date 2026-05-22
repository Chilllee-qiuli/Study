#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2020;
const int maxm = 4e6 + 120;
const int mod = 998244353;
int n;
ll a[maxn], b[maxn];

unordered_map<ll, ll> mp;
ll tr[maxn][maxn];
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

void add(int id, int i, int x){
    for(; i <= n; i += i & (-i)) tr[id][i] += x;
}

ll find(int id, int i){
    ll tmp = 0;
    for(; i; i -= i & -i) tmp += tr[id][i];
    return tmp;
}

int fidx(ll x){
    return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
}

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

        for(int i = 1; i <= n + 1; i++)
        for(int j = 1; j <= n + 1; j++) 
        tr[i][j] = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            tmp.push_back(a[i] * b[j]);

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        for(int i = 1; i < tmp.size(); i++) mp[tmp[i]] = i;

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ll now = a[i] * b[j];
                int idx = fidx(now);
                ans += find(0, idx) - find(j, idx);
                ans %= mod;
            }

            for(int j = 1; j <= n; j++){
                ll now = a[i] * b[j];
                int idx = fidx(now);
                add(0, idx, 1);
                add(j, idx, 1);
            }
        }
        cout << ans << '\n';
        cout << ans * inv[n] % mod  << endl;

        
    }

	return 0;
}
