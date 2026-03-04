#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
string s;

bool judge(string s)
{
    if (n == 1)
        return s[1] != 'b';
    if (n % 2 == 0)
    {
        if (s[1] == s[2])
            return 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == s[i] && s[i + 1] == s[i] && s[i] != '?')
                return 0;
            if (s[i] == 'a')
                cnt++;
            else if (s[i] == 'b')
                cnt--;
            else
                cnt = 0;
            if (abs(cnt) > 2)
                return 0;
        }
        return abs(cnt) <= 1;
    }
    else
    {
        if (s[1] == 'b')
            return 0;
        int cnt = 0;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] == s[i] && s[i + 1] == s[i] && s[i] != '?')
                return 0;
            if (s[i] == 'a')
                cnt++;
            else if (s[i] == 'b')
                cnt--;
            else
                cnt = 0;
            if (abs(cnt) > 2)
                return 0;
        }
        return abs(cnt) <= 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        s = '1' + s;
        if (judge(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}