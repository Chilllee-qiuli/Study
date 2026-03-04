#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{ // ax + by = gcd(a, b);
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    // a = kb + r
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll k, z;
    if(m < n){
        swap(m, n);
        swap(x, y);
    }
    ll gcd = exgcd(m - n, L, k, z); // (m - n)k + Lz = gcd(m - n, L);
    if ((y - x) % gcd != 0)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    k *= (y - x) / gcd;                        // k' * (m - n) + L * z' = gcd(m - n, L) * (y - x) / gcd(m - n, L) = y - x
    k = (k % (L / gcd) + L / gcd) % (L / gcd); // 找到最小的k
    // 通解是一个等差数列，公差是 L / gcd(m - n, L)，所以 k + t * (L / gcd(m - n, L)) 都是解
    // 证明可以看oi-wiki
    cout << k << endl;

    return 0;
}
