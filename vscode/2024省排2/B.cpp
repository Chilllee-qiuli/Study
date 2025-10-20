#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n;
int a[maxn], dp[maxn];
int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        dp[x]++;
        ans = max(ans, dp[x]);
        for(int j = 1; j * x < maxn; j++){
            dp[j*x] = max(dp[j*x], dp[x]);
        }
    }
    cout << ans << endl;

	return 0;
}
