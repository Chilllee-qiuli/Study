#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int mod = 998244353;
int a[maxn], n;
ll sum[maxn];

void work(){
    int x = a[n]/2;
    for(int i = 1; i <= n; i++) a[i] = abs(a[i] - x);
    sort(a + 1, a + 1 + n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = n; i; i--) a[i] -= a[1];

    while(a[n] >= 2) work();

    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    ll ans = 0;

    for(int i = n; i; i--){
        ans += 1ll * a[i] * i - sum[i];
        ans %= mod;
    }
    cout << ans % mod << endl;

	return 0;
}
