#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int mod =  998244353;
int n, a[maxn];
int f[maxn][2];
int g[maxn][2];
int T;

int main(){
   // freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        //memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++) cin >> a[i];
        g[0][0] = 1;

        for(int i = 1; i <= n; i++){
            g[i][0] = g[i][1] = 0;
            f[i][0] = f[i][1] = 0;

            if(a[i] != 1) {
                g[i][0] = (g[i-1][0] + g[i-1][1]) % mod;
                f[i][0] = (f[i-1][0] + f[i-1][1]) % mod;
            }
            
            if(a[i] != 0) {
                g[i][1] = (g[i-1][0] + g[i-1][1]) % mod;
                f[i][1] = (f[i-1][0] + f[i-1][1]) % mod;
                f[i][1] = (f[i][1] + g[i-1][0]) % mod;
            }
        }

        cout << (f[n][0] + f[n][1])%mod << endl;
    }

    return 0;
}