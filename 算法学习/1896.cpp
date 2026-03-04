#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 11;
int n, k;
ll dp[maxn][maxn * maxn][1 << maxn];
// dp[i][j][s]=前 i 行，第 i 行状态为 s，共放 j 个的方案数


int cpt(int x){
    int res = 0;
    while(x){
        if(x & 1) res++;
        x >>= 1;
    }
    return res;
}

bool judge(int l, int r){
    if(l & r) return 0;
    if((l << 1) & r) return 0;
    if((l >> 1) & r) return 0;
    if((r >> 1) & r) return 0;
    return 1; 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++)
    for(int j = 0; j <= k; j++) // 
    for(int l = 0; l < (1 << n); l++){
        if(cpt(l) > j) continue;
        if((l >> 1) & l) continue;
        for(int r = 0; r < (1 << n); r++){
            if(!judge(l, r)) continue;
            dp[i][j][l] += dp[i - 1][j - cpt(l)][r];
        }
    }
    ll ans = 0;
    for(int l = 0; l < (1 << n); l++)
    ans += dp[n][k][l];

    cout << ans << endl;

	return 0;
}
