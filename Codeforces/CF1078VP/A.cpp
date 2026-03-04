#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, w;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> w;
        int ans = n / w;
        ans *= w - 1;
        ans += n % w;
        cout << ans << endl;
    }

    return 0;
}
