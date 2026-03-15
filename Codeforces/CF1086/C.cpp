#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cout << fixed << setprecision(10);

    while (t--) {
        int n;
        cin >> n;
        vector<double> c(n + 1), p(n + 1), q(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> c[i] >> p[i];
            q[i] = 1.0 - p[i] / 100.0;
        }

        double dp = 0.0;  // 表示 f_{i+1}
        for (int i = n; i >= 1; i--) {
            dp = max(dp, c[i] + q[i] * dp);  // 变成 f_i
        }

        cout << dp << '\n';
    }

    return 0;
}
