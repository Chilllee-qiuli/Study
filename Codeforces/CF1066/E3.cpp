#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool check(int T, const vector<int>& H, int M, int k) {
    vector<int> G(M + 1);
    deque<int> dq;
    for (int v = 0; v <= M; v++) {
        while (!dq.empty() && dq.front() < v - T) {
            dq.pop_front();
        }
        while (!dq.empty() && H[dq.back()] >= H[v]) {
            dq.pop_back();
        }
        dq.push_back(v);
        int minH = H[dq.front()];
        G[v] = v + minH;
    }
    for (int v = 1; v <= M; v++) {
        if (G[v] > G[v - 1] + k) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int M = 3 * n;
        vector<int> cnt(M + 1, 0);
        for (int x : a) {
            if (x <= M) {
                cnt[x]++;
            }
        }
        vector<int> F(M + 1);
        F[0] = 0;
        for (int u = 1; u <= M; u++) {
            F[u] = F[u - 1] + cnt[u];
        }
        vector<int> H(M + 1);
        for (int u = 0; u <= M; u++) {
            H[u] = F[u] - u;
        }
        int low = 0, high = n, ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, H, M, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
