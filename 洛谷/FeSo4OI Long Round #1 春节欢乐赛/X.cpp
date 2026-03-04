#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define fi first
#define se second
#define mk make_pair
const int mod = 993244853;
int l, r;

int find(int d)
{
    if(l % d == 0) return l;
    return l + d - l % d;
}

bool check(int d)
{
    return find(d) + d <= r;
}

ll ans;

void work()
{
    for (int d = r - l; l < r && d; d--)
    {
        int fl = find(d);
        int fr = fl + d;
        if (fr > r)
            continue;
        //printf("d = %d, fl = %d \n", d, fl);
        ans += 1ll * d * (r - fr + 1);
        ans %= mod;
        r = fr - 1;
    }
    //cout << "end" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> l >> r;

    work();

    cout << ans << endl;
    return 0;
}