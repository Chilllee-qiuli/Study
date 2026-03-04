#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
int nxt[5050];
string s;

bool judge()
{
    for (auto it : s)
    {
        if (it != '*')
            return 0;
    }
    return 1;
}

void solve_one()
{
    cin >> n;
    cin >> s;
    stack<char> st;
    for (char c : s)
    {
        if (!st.empty() && st.top() == c)
            st.pop();
        else
            st.push(c);
    }

    if (st.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
        solve_one();

    return 0;
}
