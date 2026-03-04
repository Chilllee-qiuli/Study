#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
ll dp[maxn][2];
ll ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + a[i];
    }
    ans = max(dp[n][0], dp[n][1]);

    for(int i = 1; i <= n - 1; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + a[i];
    }
    ans = max({ans, dp[n - 1][0], dp[n - 1][1]});

    cout << ans << endl;



	return 0;
}
