#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n;
int a[maxn];
ll ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int minn = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < a[minn]) {
            minn = i;
        }
    }
    sort(a + 1, a + n + 1);
    for(int i = n; i >= 2; i--){
        ans += 1ll * a[i] * (i - 1);
        ans %= 998244353;
    }

    cout << ans << '\n';
    for(int i = 1; i <= n; i++) {
        if(i == minn) cout << -1 << " ";
        else cout << minn << " ";
    }


    return 0;
}
