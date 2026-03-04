#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500 + 5;
int t;
int n, m;
int a[maxn];

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
        int maxx = 1;
        for (int i = 1; i <= n; i++)
            if(a[i] > a[maxx]) maxx = i;
        
        // cout << "l= " << l << " r= " << r << endl;
        swap(a[1], a[maxx]);
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
