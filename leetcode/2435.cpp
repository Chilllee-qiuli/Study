#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = grid[i][j] % k;
                if (i == 0 && j == 0) continue; // 起点已经初始化过

                for (int r = 0; r < k; ++r) {
                    // 从上面来
                    if (i > 0) {
                        int fromR = r;
                        int toR = (fromR + val) % k;
                        dp[i][j][toR] = (dp[i][j][toR] + dp[i-1][j][fromR]) % MOD;
                    }
                    // 从左边来
                    if (j > 0) {
                        int fromR = r;
                        int toR = (fromR + val) % k;
                        dp[i][j][toR] = (dp[i][j][toR] + dp[i][j-1][fromR]) % MOD;
                    }
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}