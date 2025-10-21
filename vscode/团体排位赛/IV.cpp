#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll a[maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll x = 0;
    for(int t = 1; t <= k; t++){
        int p = -1;
        ll dieta = 0;
        for(int j = 0; j < m; j++){
            if(x & (1 << j)) continue;
            ll sum1 = 0, sum2 = 0;
            for(int i = 1; i <= n; i++){
                sum1 += max(a[i], a[i] ^ x);
                sum2 += max(a[i], a[i] ^ (x + (1 << j)));
            }
            if(sum2 - sum1 > dieta) p = j, dieta = sum2 - sum1;
        }
        if(p != -1) x += 1 << p;
    }
    cout << x << endl;


    return 0;
}