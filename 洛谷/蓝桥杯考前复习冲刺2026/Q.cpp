#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e7 + 10;
ll dp[maxx];
int t, m;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t >> m;

    for(int i = 1; i <= m; i++){
        int tie, val;
        cin >> tie >> val;
        for(int j = tie; j <= t; j++)
        dp[j] = max(dp[j - tie] + val, dp[j]);
    }

    cout << dp[t] << "\n";

    

    return 0;
}