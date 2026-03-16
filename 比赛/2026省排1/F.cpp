#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
int n;
int a[maxn];
int dp[maxn][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = n; i; i--){
        dp[i][1] = max(dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = min(dp[i + 1][0], dp[i + 1][1]) + a[i];
    }
    cout << min(dp[1][1], dp[1][0]) << " ";
    cout << max(dp[1][1], dp[1][0]) << "\n";

    return 0;
}