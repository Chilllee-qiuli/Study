#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10;
const int mod = 998244353;
const ll inv2 = (mod + 1) / 2;

int f[maxn][20];
int log_2[maxn];
int n;
ll ans = 0;

ll qry(int l, int r){
    int x = log_2[r - l + 1];
    return __gcd(f[l][x], f[r - (1 << x) + 1][x]);
}

ll sum_pos(int l, int r) {
    if (l > r) return 0;
    return 1ll * (l + r) % mod * (r - l + 1) % mod * inv2 % mod;
}

// 固定左端点 L，当前 gcd = g，从 startR 开始找最远右端点
int findR(int L, int startR, int g){
    int l = startR, r = n, res = startR;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(qry(L, mid) == g){
            res = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> f[i][0];

    log_2[1] = 0;
    for(int i = 2; i <= n; i++) log_2[i] = log_2[i >> 1] + 1;

    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int l = 1; l <= n; l++){
        int nowr = l;
        int nowgcd = f[l][0];

        while(nowr <= n && nowgcd != 1){
            int r = findR(l, nowr, nowgcd);

            ll segSum = sum_pos(nowr, r); // sum of right endpoints
            ans = (ans + 1ll * l % mod * segSum % mod * nowgcd) % mod;

            nowr = r + 1;
            if(nowr <= n) nowgcd = qry(l, nowr);
        }

        // 剩下的 gcd 全是 1
        if(nowr <= n){
            ll segSum = sum_pos(nowr, n);
            ans = (ans + 1ll * l % mod * segSum) % mod;
        }
    }

    cout << ans % mod << '\n';
    return 0;
}
