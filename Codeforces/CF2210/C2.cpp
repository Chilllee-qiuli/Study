#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
const int maxn = 2e5 + 10;
ll a[maxn], b[maxn];
int n;
int cnt = 0;
bool vis[(int)1e7 + 10];
int prime[maxn * 10];

ll gcd(int i, int j){
    if(i < 1 || j > n) return 1;
    return __gcd(a[i], a[j]);
}

void pre(){
    for(int i = 2; i < maxn * 10; i++){
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && (ll) prime[j] * i < maxn * 10 ; j++){
            vis[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
vector<int> fenjie(int x){
    vector<int> tmp;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) {
            tmp.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) tmp.push_back(x);
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    pre();
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        a[n + 1] = 0;

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ll gcd1 = gcd(i - 1, i), gcd2 = gcd(i, i + 1);
            ll lcm = gcd1 * gcd2 / __gcd(gcd1, gcd2);
            //  cout << lcm << " ";
            if(b[i] >= lcm){
                if(a[i] != lcm) ans++;
                else {
                    if(a[i + 1] && a[i + 1] % b[i] == 0) continue;
                    if(a[i - 1] && a[i - 1] % b[i] == 0) continue;
                    ans++;
                }
            }
        }
        // cout << endl;
        cout << ans << endl;
    }

	return 0;
}
