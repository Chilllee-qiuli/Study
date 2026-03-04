#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
string s;

bool match(char pat, char real) {
    return pat == '?' || pat == real;
}

bool judge() {
    bool dp[2] = {1, 0}; 
    for (int i = 1; i <= n; i++) {
        bool ndp[2] = {0, 0};
        char ttmp = s[i - 1];

        for (int p = 0; p <= 1; p++) // 表示当前端点状态
        if (dp[p]) {
            char left = (p == 0 ? 'a' : 'b');
            int odd_r = ((n - i + 1) & 1) ^ p;
            char right = odd_r ? 'a' : 'b';

            if (match(ttmp, left))  ndp[p ^ 1] = 1; 
            if (match(ttmp, right)) ndp[p] = 1;     
        }
        dp[0] = ndp[0];
        dp[1] = ndp[1];
        if (!dp[0] && !dp[1]) return false; 
    }
    return dp[0] || dp[1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        cout << (judge() ? "YES\n" : "NO\n");
    }
    return 0;
}
