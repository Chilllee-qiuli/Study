#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 1;
        int m = n;
        for (int i = 2; i * i <= n; i++)
        {
            if (m % i == 0)
            {
                ans *= i;
                while (m % i == 0)
                    m /= i;
                // cout << "i = " << i << " m = " << m << endl;
            }
            if (m == 1)
                break;
        }
        cout << ans * m << endl;
    }

    return 0;
}
