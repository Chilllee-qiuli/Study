#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int t;
int a[maxn];
int n;


int main() {
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--) {

        cin >> n;
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 == 0) {
                tmp += a[i];
            } else {
                tmp -= a[i];
            }
        }
        ll best = 0;
        ll cur = 0;
        for (int i = 0; i < n - 1; i += 2) {
            cur += a[i + 1] - a[i];
            if (cur < 0) cur = 0;
            best = max(best, cur);
        }
        cur = 0;
        for (int i = 1; i < n - 1; i += 2) {
            cur += a[i] - a[i + 1];
            if (cur < 0) cur = 0;
            best = max(best, cur);
        }
        cout << tmp + best << endl;
    }
    return 0;
}
