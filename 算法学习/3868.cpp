#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m[20], M[20], MM = 1, a[20];
ll t[20];

ll mul(ll a, ll b, ll p)
{
    ll d = (ll)(a * (long double)b / p + 0.5);
    ll c = a * b - d * p;
    return c < 0 ? c + p : c;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll inv(ll a, ll p)
{
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
    // 规范在模p的界限内
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        MM *= m[i];
    }

    for (int i = 1; i <= n; i++)
    {
        M[i] = MM / m[i];
        t[i] = inv(M[i], m[i]);
    }
    ll x = 0;
    for (int i = 1; i <= n; i++)
    {
        x += (__int128)a[i] * t[i] % MM * M[i] % MM;
        x %= MM;
    }

    cout << x << endl;
    return 0;
}
