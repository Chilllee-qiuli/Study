#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int t;
int n;
int a[maxn];
int tl[maxn], tr[maxn];
int qu[maxn], cnt = 0;

void solve_one()
{
    cin >> n;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (a[i] > a[qu[cnt]] && cnt > 0)
            cnt--;
        qu[++cnt] = i;
        tl[i] = cnt;
    }
    cnt = 0;
    for (int i = n; i; i--)
    {
        while (a[i] > a[qu[cnt]] && cnt > 0)
            cnt--;
        qu[++cnt] = i;
        tr[i] = cnt;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, tl[i] + tr[i] - 1);

    cout << n - ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve_one();
    }

    return 0;
}
