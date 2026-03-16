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

    // dp[i][0] 定义为这一次没吃到，结束后下一轮肯定有主动权
    // dp[i][1] 定义为这一次吃到了，结束后下一轮肯定没有主动权
    for(int i = n; i >= 0; i--){
        // 有主动权的可以主动找max
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
        // 没有主动权的只能被动拿min的那一边
        dp[i][1] = min(dp[i + 1][0], dp[i + 1][1]) + a[i];
    }
    cout << min(dp[1][1], dp[1][0]) << " ";
    cout << max(dp[1][1], dp[1][0]) << "\n";

    return 0;
}