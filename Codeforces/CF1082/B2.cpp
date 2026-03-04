#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string X;
        cin >> n >> X;
        
        string T(n, ' ');
        for (int i = 0; i < n; ++i) {
            T[i] = (i % 2 == 0) ? 'a' : 'b';
        }
        
        // 初始化DP表
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            if (X[0] == '?' || X[0] == T[i]) {
                dp[i][i] = true;
            }
        }
        
        // 按区间长度从小到大填充DP表
        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len <= n; ++l) {
                int r = l + len - 1;
                int k = n - len; // 当前要匹配的X的下标
                
                bool can_left = false;
                if (X[k] == '?' || X[k] == T[l]) {
                    can_left = dp[l+1][r];
                }
                
                bool can_right = false;
                if (X[k] == '?' || X[k] == T[r]) {
                    can_right = dp[l][r-1];
                }
                
                dp[l][r] = can_left || can_right;
            }
        }
        
        if (dp[0][n-1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}