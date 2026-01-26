#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 202;
ll s[maxn];
int n, m;
int flag;
int vis[maxn];

void print() {
    int lst = 0;
    for (int i = n; i >= 1; i--) {
        if (vis[i]) {
            lst = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            cout << s[i];
            if (i != lst) cout << " ";
        }
    }
}

void dfs(int idx, ll now) {
    if (idx > n) {
        if (now == m) {
            if (!flag) {
                print();
                flag = 1;
            }
        }
        return;
    }
    if (now > m) return;
    if (now == m) {
        if (!flag) {
            print();
            flag = 1;
        }
        return;
    }
    vis[idx] = 1;
    dfs(idx + 1, now + s[idx]);
    vis[idx] = 0;
    dfs(idx + 1, now);
}

int main() {
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + 1 + n);
    dfs(1, 0);
    return 0;
}
