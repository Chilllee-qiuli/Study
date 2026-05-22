#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n;
int a[N];
unordered_map<int, int> mp;
int b[N];
int cnt;
struct tre
{
    int mxcnt, mxv;
} tr[N << 2];
void push_up(int k)
{
    if (tr[k << 1].mxv == tr[k << 1 | 1].mxv)
    {
        tr[k].mxcnt = tr[k << 1].mxcnt + tr[k << 1 | 1].mxcnt;
        tr[k].mxv = tr[k << 1].mxv;
    }
    else
    {
        if (tr[k << 1].mxcnt > tr[k << 1 | 1].mxcnt)
        {
            tr[k].mxcnt = tr[k << 1].mxcnt;
            tr[k].mxv = tr[k << 1].mxv;
        }
        else if (tr[k << 1].mxcnt < tr[k << 1 | 1].mxcnt)
        {
            tr[k].mxcnt = tr[k << 1 | 1].mxcnt;
            tr[k].mxv = tr[k << 1 | 1].mxv;
        }
        else if (tr[k << 1].mxv > tr[k << 1 | 1].mxv)
        {
            tr[k].mxcnt = tr[k << 1].mxcnt;
            tr[k].mxv = tr[k << 1].mxv;
        }
        else
        {
            tr[k].mxcnt = tr[k << 1 | 1].mxcnt;
            tr[k].mxv = tr[k << 1 | 1].mxv;
        }
    }
    return;
}
void push_down(int k)
{
}
void build(int l, int r, int k)
{
    tr[k].mxcnt = 0;
    tr[k].mxv = 0;
    if (l == r)
    {
        tr[k].mxcnt = 0;
        tr[k].mxv = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, k << 1);
    build(mid + 1, r, k << 1 | 1);
    return;
}
void add(int l, int r, int k, int x)
{
    if (l == r)
    {
        tr[k].mxcnt++;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        add(l, mid, k << 1, x);
    else
        add(mid + 1, r, k << 1 | 1, x);
    push_up(k);
    return;
}
void solve()
{
    mp.clear();
    cnt = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (mp[a[i]] == 0)
        {
            mp[a[i]] = ++cnt;
            b[cnt] = a[i];
        }
        else
        {
            continue;
        }
    }
    build(1, cnt, 1);
    int mxp = -1, mxnum = 0, mnp = 1e9 + 1, mnnum = 0;
    for (int i = 1; i <= n; i++)
    {
        add(1, cnt, 1, mp[a[i]]);
        if (a[i] > mxp)
        {
            mxp = a[i];
            mxnum = 1;
        }
        else if (a[i] == mxp)
        {
            mxnum++;
        }
        if (a[i] < mnp)
        {
            mnp = a[i];
            mnnum = 1;
        }
        else if (a[i] == mnp)
        {
            mnnum++;
        }
        int ans = 0;
        int z = 0, znum = 0;
        z = tr[1].mxv;
        znum = tr[1].mxcnt;
        if (i == (mxnum + mnnum))
        {
            if (z == mxp && mnnum == 1)
            {
                ans = max(z + z, mxp + mnp);
            }
            else if (z == mnp && mxnum == 1)
            {
                ans = max(z + z, mxp + mnp);
            }
            else
            {
                ans = mxp + mnp;
            }
        }
        else
        {
            ans = mxp + mnp;
        }
        cout << ans << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}