#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int n, k;
int h[maxn];

int qumax[maxn], lmax, rmax;
int qumin[maxn], lmin, rmin;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    lmin = lmax = 1;
    for (int i = 1; i <= n; i++)
    {
        while (lmax <= rmax && qumax[lmax] + k <= i)
            lmax++;
        while (lmax <= rmax && h[qumax[rmax]] < h[i])
            rmax--;
        qumax[++rmax] = i;
        while (lmin <= rmin && qumin[lmin] + k <= i)
            lmin++;
        while (lmin <= rmin && h[qumin[rmin]] > h[i])
            rmin--;
        qumin[++rmin] = i;
        if(i >= k)ans = max(ans, h[qumax[lmax]] - h[qumin[lmin]]);
    }

    cout << ans << endl;

    return 0;
}
