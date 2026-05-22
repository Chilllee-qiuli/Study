#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
const int N = 200010, mod = 998244353;
struct data1
{
    ll a, b;
} a[N];
bool pd1(data1 d1, data1 d2)
{
    return d1.b > d2.b;
}
ll ksm(ll a, ll b)
{
    ll base = 1;
    while (b)
    {
        if (b & 1)
        {
            base = base * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return base;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + n + 1, pd1);
    ll res = 0, base = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res != 0)
        {
            if (log2(res) + base - a[i].b > 62)
            {
                // cout << "break\n";
                break;
            }
            else
            {
                res *= pow(2, (base - a[i].b)); // 个数
            }
            base = a[i].b;
            if (a[i].a <= res)
            {
                res -= a[i].a;
                a[i].a = 0;
            }
            else
            {
                a[i].a -= res;
                res = 0;
            }
        }
        if (a[i].a != 0)
        { // deng tong yu 'res' bu gou yong
            ll cnt = (a[i].a + m - 1) / m;
            ans += cnt * ksm(2, a[i].b) % mod; //
            ans %= mod;
            res = (m - a[i].a % m) % m;
            base = a[i].b;
        }
    }
    cout << ans << '\n';
    return;
}
int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}