#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
#define fi first
#define se second
const int maxn = 1010;
int n, a, b;

pr man[maxn];

struct Large
{
    int num[4040];
    Large()
    {
        memset(num, 0, sizeof(num));
    }
    Large operator*(int x)
    {
        for (int i = 4002; i >= 0; i--)
            num[i] = num[i] * x;
        
        for (int i = 0; i < 4003; i++)
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        return *this;
    }

    Large operator/(int x)
    {
        Large res;
        int rem = 0;
        for (int i = 4002; i >= 0; i--)
        {
            rem = rem * 10 + num[i];
            res.num[i] = rem / x;
            rem %= x;
        }
        return res;
    }

    bool operator<(const Large &x) const
    {
        for (int i = 4002; i >= 0; i--)
        {
            if (num[i] != x.num[i])
                return num[i] < x.num[i];
        }
        return false;
    }

    void print()
    {
        for (int i = 4002; i >= 0; i--){
            if (num[i] != 0){
                for (int j = i; j >= 0; j--){
                    cout << num[j];
                }
                cout << "\n";
                return;
            }
            if (i == 0){
                cout << "0\n";
                return;
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> man[i].fi >> man[i].se;
    }

    sort(man + 1, man + 1 + n, [](pr x, pr y)
         { return x.fi * x.se < y.fi * y.se; });

    Large cur;
    cur.num[0] = a;
    Large ans;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, cur / man[i].se);
        cur = cur * man[i].fi;
    }

    ans.print();

    return 0;
}
