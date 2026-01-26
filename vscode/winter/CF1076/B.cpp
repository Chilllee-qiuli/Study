#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
int a[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int l = 1;
        while (a[l] == n - l + 1)
            l++;
        int r = n;
        while (a[r] != n - l + 1)
            r--;
        reverse(a + l, a + r + 1);
        for (int i = 1; i <= n; i++)
            cout << a[i] << " \n"[i == n];
    }

    return 0;
}