#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        int cnt = 0, flag = 0;
        if (s[0] != s[n - 1])
        {
            for (int i = 1; i < n; i++)
            {
                if (s[i] == s[i - 1])
                    flag = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                cnt++;
            else if (s[i] != s[i - 1])
                cnt++;
        }
        cout << cnt + flag << "\n";
    }

    return 0;
}