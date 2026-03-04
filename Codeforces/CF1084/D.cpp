#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
const int maxn = 2e5 + 10;
int n, x, y;
int a[maxn];

void solve_one()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int minn = 0;
    vector<int> ansb, ans;
    for (int i = x + 1; i <= y; i++)
        if (!minn || a[i] < a[minn]) minn = i;


    for (int i = minn; i <= y; i++)
        ansb.push_back(a[i]);
    for (int i = x + 1; i < minn; i++)
        ansb.push_back(a[i]);
    // // cout << "test: " << minn << endl;
    // int minn2 = 0;

    int flag = 0;
    for (int i = 1; i <= x; i++)
    {
        if (a[minn] < a[i]){
            flag = i;
            break;
        }
    }
    if (flag)
    {
        for (int i = 1; i < flag; i++)
            ans.push_back(a[i]);
        for (auto it : ansb)
            ans.push_back(it);
        for (int i = flag; i <= x; i++)
            ans.push_back(a[i]);
        for (int i = y + 1; i <= n; i++)
            ans.push_back(a[i]);
    }
    else
    {
        for (int i = y + 1; i <= n; i++)
            if (a[minn] < a[i])
            {
                flag = i;
                break;
            }
        
            if (!flag)
                flag = n + 1;
            for (int i = 1; i <= x; i++)
                ans.push_back(a[i]);
            for (int i = y + 1; i < flag; i++)
                ans.push_back(a[i]);
            for (auto it : ansb)
                ans.push_back(it);
            for (int i = flag; i <= n; i++)
                ans.push_back(a[i]);
    }

        for (auto it : ans)
            cout << it << " ";
        cout << "\n";
    
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
