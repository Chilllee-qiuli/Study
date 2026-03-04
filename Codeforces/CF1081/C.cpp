#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn];
ll tmp[maxn];
ll pre[maxn], mmin[maxn];
int t;
int n, k;
ll tme; // time
ll sum, h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> h >> k;
        sum = 0;
        tme = 0;
        mmin[0] = 1e18;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
            pre[i] = pre[i - 1] + a[i];
             mmin[i] = min(mmin[i - 1], a[i]);
        }
        tmp[n + 1] = 0;
        for (int i = n; i; i--)
            tmp[i] = max(tmp[i + 1], a[i]);

        ll cntt = 0;
        cntt = (h - 1) / sum;
        tme += cntt * (n + k);
        h -= cntt * sum;

        int ans = n;
        for(int i = 1; i <= n; i++){
            ll now = pre[i];
            if(i != n){
                now = max(now, pre[i] - mmin[i] + tmp[i + 1]);
            }
            if(now >= h){
                ans = i;
                break;
            }
        }
        cout << tme + ans << endl;
    }

    return 0;
}
